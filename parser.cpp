#include "commands.h"
#include "parser.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <map>


std::vector<BaseCommand *> parse_commands(const std::string &filename) {

    std::map<std::string, int> mapping;
    mapping["BEGIN"] = BEGIN;
    mapping["END"] = END;
    mapping["PUSH"] = PUSH;
    mapping["POP"] = POP;
    mapping["PUSHR"] = PUSHR;
    mapping["POPR"] = POPR;
    mapping["ADD"] = ADD;
    mapping["SUB"] = SUB;
    mapping["MUL"] = MUL;
    mapping["DIB"] = DIV;
    mapping["OUT"] = OUT;
    mapping["IN"] = IN;

    std::vector<BaseCommand *> commands;
    std::string command_name;
    std::ifstream input(filename);
    while (input >> command_name) {
        switch (mapping[command_name]) {
            case BEGIN:
                commands.push_back(new BeginCommand());
                break;
            case END:
                commands.push_back(new EndCommand());
                break;
            case PUSH:
                int val;
                input >> val;
                commands.push_back(new PushCommand(val));
                break;
            case POP:
                commands.push_back(new PopCommand());
                break;
            case PUSHR:
                int reg_index;
                input >> reg_index;
                commands.push_back(new PushrCommand(reg_index));
                break;
            case POPR:
                int reg;
                input >> reg;
                commands.push_back(new PoprCommand(reg));
                break;
            case ADD:
                commands.push_back(new AddCommand());
                break;
            case SUB:
                commands.push_back(new SubCommand());
                break;
            case MUL:
                commands.push_back(new MulCommand());
                break;
            case DIV:
                commands.push_back(new DivCommand());
                break;
            case OUT:
                commands.push_back(new OutCommand());
                break;
            case IN:
                commands.push_back(new InCommand());
                break;
        }
    }
    return commands;
}