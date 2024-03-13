//
// Created by Andrey Kizhinov on 3/13/24.
//

#ifndef STACK_PROJECT_EMULATOR_H
#define STACK_PROJECT_EMULATOR_H

#include <string>
#include "include/Stack.h"

class Memory {
private:
    stack_namespace::Stack<int> stack;
    int reg[16]{};
public:
    stack_namespace::Stack<int>& get_stack() {
        return stack;
    }

    int *get_register() {
        return reg;
    }

};

void start_program(const std::string &filename);

#endif //STACK_PROJECT_EMULATOR_H
