#ifndef STACK_PROJECT_COMMANDS_H
#define STACK_PROJECT_COMMANDS_H

#include "include/Stack.h"
#include "enum_commands.h"
#include <string>
#include <iostream>

class BaseCommand {
private:
    CommandName name = CommandName::BEGIN;
public:
    virtual ~BaseCommand() = default;

    virtual int get_index(stack_namespace::Stack<int> &stack) const = 0;

    virtual void run_command(stack_namespace::Stack<int> &stack) const = 0;

    virtual void run_command(stack_namespace::Stack<int> &stack, int *reg) const = 0;

    [[nodiscard]] virtual CommandName get_name() const = 0;
};

class BeginCommand : public BaseCommand {
private:
    CommandName name = CommandName::BEGIN;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack) const override {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class EndCommand : public BaseCommand {
private:
    CommandName name = CommandName::END;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack) const override {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class PushCommand : public BaseCommand {
private:
    CommandName name = CommandName::PUSH;
    int val;
public:
    explicit PushCommand(int val) : val(val) {}

    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack) const override {
        stack.push(val);
    };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class PopCommand : public BaseCommand {
private:
    CommandName name = CommandName::POP;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack) const override {
        stack.pop();
    };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class PushrCommand : public BaseCommand {
private:
    CommandName name = CommandName::PUSHR;
    int reg_index;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    explicit PushrCommand(int reg_index) : reg_index(reg_index) {}

    void run_command(stack_namespace::Stack<int> &stack) const override {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {
        stack.push(reg[reg_index]);
    };

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class PoprCommand : public BaseCommand {
private:
    CommandName name = CommandName::POPR;
    int reg_index;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    explicit PoprCommand(int reg_index) : reg_index(reg_index) {}

    void run_command(stack_namespace::Stack<int> &stack) const override {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {
        reg[reg_index] = stack.top();
        stack.pop();
    };

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class AddCommand : public BaseCommand {
private:
    CommandName name = CommandName::ADD;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int first = stack.top();
        stack.pop();
        int second = stack.top();
        stack.pop();
        stack.push(first + second);
    };

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class SubCommand : public BaseCommand {
private:
    CommandName name = CommandName::SUB;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int first = stack.top();
        stack.pop();
        int second = stack.top();
        stack.pop();
        stack.push(first - second);
    };

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class MulCommand : public BaseCommand {
private:
    CommandName name = CommandName::MUL;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int first = stack.top();
        stack.pop();
        int second = stack.top();
        stack.pop();
        stack.push(first * second);
    };

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class DivCommand : public BaseCommand {
private:
    CommandName name = CommandName::DIV;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int first = stack.top();
        stack.pop();
        int second = stack.top();
        stack.pop();
        stack.push(first / second);
    };

    [[nodiscard]]  CommandName get_name() const override {
        return name;
    }
};

class OutCommand : public BaseCommand {
private:
    CommandName name = CommandName::OUT;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int val = stack.top();
        stack.pop();
        std::cout << val << "\n";
    };

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class InCommand : public BaseCommand {
private:
    CommandName name = CommandName::IN;
public:
    int get_index(stack_namespace::Stack<int> &stack) const override { return -1; };

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {
        int val;
        std::cin >> val;
        stack.push(val);
    };

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class JmpCommand : public BaseCommand {
private:
    CommandName name = CommandName::JMP;
    int jump_index;
public:
    explicit JmpCommand() {
        jump_index = 0;
    }

    explicit JmpCommand(int jump_index) : jump_index(jump_index) {}

    void run_command(stack_namespace::Stack<int> &stack, int *reg) const override {}

    void run_command(stack_namespace::Stack<int> &stack) const override {};

    static std::pair<int, int> get_first_second(stack_namespace::Stack<int> &stack) {
        int first_val = stack.top();
        stack.pop();
        int second_val = stack.top();
        stack.push(first_val);
        std::pair<int, int> f_s = {first_val, second_val};
        return f_s;
    }

    int get_index(stack_namespace::Stack<int> &stack) const override {
        return jump_index;
    }

    [[nodiscard]] CommandName get_name() const override {
        return name;
    }
};

class JeqCommand : public JmpCommand {
private:
    CommandName name = CommandName::JEQ;
    int jump_index{};
public:
    explicit JeqCommand(int jump_index) : jump_index(jump_index) {}

    int get_index(stack_namespace::Stack<int> &stack) const override {
        std::pair<int, int> f_s = get_first_second(stack);
        if (f_s.first == f_s.second) {
            return jump_index;
        }
        return -1;
    }
};

class JneCommand : public JmpCommand {
private:
    CommandName name = CommandName::JNE;
    int jump_index = -1;
public:
    explicit JneCommand(int jump_index) : jump_index(jump_index) {}

    int get_index(stack_namespace::Stack<int> &stack) const override {
        std::pair<int, int> f_s = get_first_second(stack);
        if (f_s.first != f_s.second) {
            return jump_index;
        }
        return -1;
    }
};

class JaCommand : public JmpCommand {
private:
    CommandName name = CommandName::JA;
    int jump_index = -1;
public:
    explicit JaCommand(int jump_index) : jump_index(jump_index) {}

    int get_index(stack_namespace::Stack<int> &stack) const override {
        std::pair<int, int> f_s = get_first_second(stack);
        if (f_s.first > f_s.second) {
            return jump_index;
        }
        return -1;
    }
};

class JaeCommand : public JmpCommand {
private:
    CommandName name = CommandName::JAE;
    int jump_index = -1;
public:
    explicit JaeCommand(int jump_index) : jump_index(jump_index) {}

    int get_index(stack_namespace::Stack<int> &stack) const override {
        std::pair<int, int> f_s = get_first_second(stack);
        if (f_s.first >= f_s.second) {
            return jump_index;
        }
        return -1;
    }
};

class JbCommand : public JmpCommand {
private:
    CommandName name = CommandName::JB;
    int jump_index = -1;
public:
    explicit JbCommand(int jump_index) : jump_index(jump_index) {}

    int get_index(stack_namespace::Stack<int> &stack) const override {
        std::pair<int, int> f_s = get_first_second(stack);
        if (f_s.first < f_s.second) {
            return jump_index;
        }
        return -1;
    }
};

class JbeCommand : public JmpCommand {
private:
    CommandName name = CommandName::JBE;
    int jump_index = -1;
public:
    explicit JbeCommand(int jump_index) : jump_index(jump_index) {}

    int get_index(stack_namespace::Stack<int> &stack) const override {
        std::pair<int, int> f_s = get_first_second(stack);
        if (f_s.first <= f_s.second) {
            return jump_index;
        }
        return -1;
    }
};

#endif