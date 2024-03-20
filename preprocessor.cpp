#include "emulator.h"
#include "commands.h"
#include "parser.h"
#include <vector>

void run_program(Memory &memory, const std::string &filename) {
    std::vector<BaseCommand *> commands = parse_commands(filename);
    bool started = false;
    for (auto el: commands) {
        if (!started) {
            if (el->get_name() == CommandName::BEGIN) {
                started = true;
            }
            continue;
        }
        if (el->get_name() == CommandName::END) {
            break;
        }
        if (el->get_name() == CommandName::PUSHR || el->get_name() == CommandName::POPR) {
            el->run_command(memory.get_stack(), memory.get_register());
        } else {
            el->run_command(memory.get_stack());
        }
    }
}