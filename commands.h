#ifndef STACK_PROJECT_COMMANDS_H
#define STACK_PROJECT_COMMANDS_H

#include "include/Stack.h"
#include <string>
#include <iostream>

class BaseCommand {
private:
    std::string name;
public:
    virtual ~BaseCommand() = default;

    virtual void run_command(stack_namespace::Stack<int> &stack) const = 0;

    virtual void run_command(stack_namespace::Stack<int> &stack, int *reg) const = 0;

    [[nodiscard]] virtual std::string get_name() const = 0;
};

class BeginCommand : public BaseCommand {
private:
    std::string name = "BEGIN";
public:
    void run_command(stack_namespace::Stack<int> &stack) const override {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class EndCommand : public BaseCommand {
private:
    std::string name = "END";
public:
    void run_command(stack_namespace::Stack<int> &stack) const override {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class PushCommand : public BaseCommand {
private:
    std::string name = "PUSH";
    int val;
public:
    explicit PushCommand(int val) : val(val) {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        stack.push(val);
    };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class PopCommand : public BaseCommand {
private:
    std::string name = "POP";
public:

    void run_command(stack_namespace::Stack<int> &stack) const override {
        stack.pop();
    };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class PushrCommand : public BaseCommand {
private:
    std::string name = "PUSHR";
    int reg_index;
public:
    explicit PushrCommand(int reg_index) : reg_index(reg_index) {}

    void run_command(stack_namespace::Stack<int> &stack) const override {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {
        stack.push(reg[reg_index]);
    };

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class PoprCommand : public BaseCommand {
private:
    std::string name = "POPR";
    int reg_index;
public:
    explicit PoprCommand(int reg_index) : reg_index(reg_index) {}

    void run_command(stack_namespace::Stack<int> &stack) const override {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {
        reg[reg_index] = stack.top();
        stack.pop();
    };

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class AddCommand : public BaseCommand {
private:
    std::string name = "ADD";
public:
    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int first = stack.top();
        stack.pop();
        int second = stack.top();
        stack.pop();
        stack.push(first + second);
    };

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class SubCommand : public BaseCommand {
private:
    std::string name = "SUB";
public:
    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int first = stack.top();
        stack.pop();
        int second = stack.top();
        stack.pop();
        stack.push(first - second);
    };

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class MulCommand : public BaseCommand {
private:
    std::string name = "MUL";
public:
    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int first = stack.top();
        stack.pop();
        int second = stack.top();
        stack.pop();
        stack.push(first * second);
    };

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class DivCommand : public BaseCommand {
private:
    std::string name = "DIV";
public:
    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int first = stack.top();
        stack.pop();
        int second = stack.top();
        stack.pop();
        stack.push(first / second);
    };

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class OutCommand : public BaseCommand {
private:
    std::string name = "OUT";
public:
    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int val = stack.top();
        stack.pop();
        std::cout << val << "\n";
    };

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

class InCommand : public BaseCommand {
private:
    std::string name = "IN";
public:
    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int val;
        std::cin >> val;
        stack.push(val);
    };

    [[nodiscard]] std::string get_name() const override {
        return name;
    }
};

#endif