#ifndef STACK_PROJECT_PARSER_H
#define STACK_PROJECT_PARSER_H

#include "commands.h"

std::vector<BaseCommand *> parse_commands(const std::string &filename);

#endif
