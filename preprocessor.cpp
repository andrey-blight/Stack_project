#include "emulator.h"
#include "commands.h"
#include "parser.h"
#include <vector>

void run_program(Memory &memory, const std::string &filename) {
    std::vector<BaseCommand *> commands = parse_commands(filename);
    bool started = false;
    for (auto el: commands) {
        if (!started) {
            if (el->get_name() == "BEGIN") {
                started = true;
            }
            continue;
        }
        if (el->get_name() == "END") {
            break;
        }
        if (el->get_name() == "PUSHR" || el->get_name() == "POPR") {
            el->run_command(memory.get_stack(), memory.get_register());
        } else {
            el->run_command(memory.get_stack());
        }
    }
}