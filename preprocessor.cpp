#include "emulator.h"
#include "commands.h"
#include "parser.h"
#include <vector>
#include <set>

void run_program(Memory &memory, const std::string &filename) {
    std::vector<BaseCommand *> commands = parse_commands(filename);
    std::set<CommandName> jump_commands = {CommandName::JMP, CommandName::JEQ, CommandName::JNE, CommandName::JA,
                                           CommandName::JAE, CommandName::JB, CommandName::JBE};
    bool started = false;
    int i = 0;
    while (i < commands.size()) {
        auto el = commands[i];
        if (!started) {
            if (el->get_name() == CommandName::BEGIN) {
                started = true;
            }
            ++i;
            continue;
        }
        if (el->get_name() == CommandName::END) {
            break;
        }
        if (el->get_name() == CommandName::PUSHR || el->get_name() == CommandName::POPR) {
            el->run_command(memory.get_stack(), memory.get_register());
            ++i;
        } else if (jump_commands.find(el->get_name()) != jump_commands.end()) {
            int index = el->get_index(memory.get_stack());
            if (index == -1) {
                ++i;
            } else {
                i = index;
            }
        } else {
            el->run_command(memory.get_stack());
            ++i;
        }
    }
}