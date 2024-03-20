#include "commands.h"
#include "parser.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "enum_commands.h"
#include <stdexcept>

std::map<std::string, int> get_labels(std::map<std::string, CommandName> &mapping, const std::string &filename) {
    std::map<std::string, int> label_line;
    std::set<CommandName> zero_arg = {CommandName::BEGIN, CommandName::END, CommandName::POP, CommandName::ADD,
                                      CommandName::SUB, CommandName::MUL, CommandName::DIV, CommandName::OUT,
                                      CommandName::IN};

    std::string command_name;
    std::ifstream input(filename);
    int count_commands = 0;
    while (input >> command_name) {
        if (mapping.find(command_name) == mapping.end()) {
            label_line[command_name] = count_commands;
            continue;
        }
        CommandName cmd = mapping[command_name];
        if (zero_arg.find(cmd) != zero_arg.end()) {
            ++count_commands;
        } else {
            std::string val;
            input >> val;
            ++count_commands;
        }
    }
    return label_line;
}

std::vector<BaseCommand *> parse_commands(const std::string &filename) {

    std::map<std::string, CommandName> mapping;
    mapping["BEGIN"] = CommandName::BEGIN;
    mapping["END"] = CommandName::END;
    mapping["PUSH"] = CommandName::PUSH;
    mapping["POP"] = CommandName::POP;
    mapping["PUSHR"] = CommandName::PUSHR;
    mapping["POPR"] = CommandName::POPR;
    mapping["ADD"] = CommandName::ADD;
    mapping["SUB"] = CommandName::SUB;
    mapping["MUL"] = CommandName::MUL;
    mapping["DIB"] = CommandName::DIV;
    mapping["OUT"] = CommandName::OUT;
    mapping["JMP"] = CommandName::JMP;
    mapping["JEQ"] = CommandName::JEQ;
    mapping["JNE"] = CommandName::JNE;
    mapping["JA"] = CommandName::JA;
    mapping["JAE"] = CommandName::JAE;
    mapping["JB"] = CommandName::JB;
    mapping["JBE"] = CommandName::JBE;


    std::map<std::string, int> label_line = get_labels(mapping, filename);

    std::vector<BaseCommand *> commands;
    std::string command_name;
    std::string lbl;
    std::ifstream input(filename);
    while (input >> command_name) {
        switch (mapping[command_name]) {
            case CommandName::BEGIN:
                commands.push_back(new BeginCommand());
                break;
            case CommandName::END:
                commands.push_back(new EndCommand());
                break;
            case CommandName::PUSH:
                int val;
                input >> val;
                commands.push_back(new PushCommand(val));
                break;
            case CommandName::POP:
                commands.push_back(new PopCommand());
                break;
            case CommandName::PUSHR:
                int reg_index;
                input >> reg_index;
                commands.push_back(new PushrCommand(reg_index));
                break;
            case CommandName::POPR:
                int reg;
                input >> reg;
                commands.push_back(new PoprCommand(reg));
                break;
            case CommandName::ADD:
                commands.push_back(new AddCommand());
                break;
            case CommandName::SUB:
                commands.push_back(new SubCommand());
                break;
            case CommandName::MUL:
                commands.push_back(new MulCommand());
                break;
            case CommandName::DIV:
                commands.push_back(new DivCommand());
                break;
            case CommandName::OUT:
                commands.push_back(new OutCommand());
                break;
            case CommandName::IN:
                commands.push_back(new InCommand());
                break;
            case CommandName::JMP:
                input >> lbl;
                if (label_line.find(lbl) == label_line.end()) {
                    throw std::invalid_argument("label not find");
                }
                commands.push_back(new JmpCommand(label_line[lbl]));
                break;
            case CommandName::JEQ:
                input >> lbl;
                if (label_line.find(lbl) == label_line.end()) {
                    throw std::invalid_argument("label not find");
                }
                commands.push_back(new JeqCommand(label_line[lbl]));
                break;
            case CommandName::JNE:
                input >> lbl;
                if (label_line.find(lbl) == label_line.end()) {
                    throw std::invalid_argument("label not find");
                }
                commands.push_back(new JneCommand(label_line[lbl]));
                break;
            case CommandName::JA:
                input >> lbl;
                if (label_line.find(lbl) == label_line.end()) {
                    throw std::invalid_argument("label not find");
                }
                commands.push_back(new JaCommand(label_line[lbl]));
                break;
            case CommandName::JAE:
                input >> lbl;
                if (label_line.find(lbl) == label_line.end()) {
                    throw std::invalid_argument("label not find");
                }
                commands.push_back(new JaeCommand(label_line[lbl]));
                break;
            case CommandName::JB:
                input >> lbl;
                if (label_line.find(lbl) == label_line.end()) {
                    throw std::invalid_argument("label not find");
                }
                commands.push_back(new JbCommand(label_line[lbl]));
                break;
            case CommandName::JBE:
                input >> lbl;
                if (label_line.find(lbl) == label_line.end()) {
                    throw std::invalid_argument("label not find");
                }
                commands.push_back(new JbeCommand(label_line[lbl]));
                break;
        }
    }
    return commands;
}