#include "include/Stack.h"
#include <iostream>

int main() {
    stack_namespace::Stack<int> stack;
    stack.push(4);
    stack.push(5);
    stack.pop();
    std::cout << stack.top();
}