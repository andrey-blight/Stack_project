#ifndef STACK_PROJECT_PARSER_H
#define STACK_PROJECT_PARSER_H


#define BEGIN 1
#define END 2
#define PUSH 3
#define POP 4
#define PUSHR  5
#define POPR  6
#define ADD 7
#define SUB 8
#define MUL 9
#define DIV 10
#define OUT 11
#define IN 12

std::vector<BaseCommand *> parse_commands(const std::string &filename);

#endif
