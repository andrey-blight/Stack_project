#include "commands.h"
#include "parser.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include "enum_commands.h"


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
    mapping["IN"] = CommandName::IN;

    std::vector<BaseCommand *> commands;
    std::string command_name;
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
        }
    }
    return commands;
}