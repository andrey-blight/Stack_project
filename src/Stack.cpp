#include "include/Stack.h"

namespace stack_namespace {

//    template<class Type>
//    void Stack<Type>::realloc() {
//        MAX_SIZE *= 2;
//
//        Type new_arr = new Type(MAX_SIZE);
//        for (int i = 0; i <= index; ++i) {
//            new_arr[i] = arr[i];
//        }
//
//        delete[] arr;
//        arr = new_arr;
//    }

//    template<class Type>
//    Stack<Type>::Stack() {
//        MAX_SIZE = 100;
//        arr = new Type(MAX_SIZE);
//        index = 0;
//    }

//    template<class Type>
//    Stack<Type>::~Stack() {
//        delete[] arr;
//    }

    template<class Type>
    Stack<Type>::Stack(const Stack &other) {
        MAX_SIZE = other.MAX_SIZE;
        arr = new Type(MAX_SIZE);
        index = other.index;
        for (int i = 0; i <= index; ++i) {
            arr[i] = other.arr[i];
        }
    }

    template<class Type>
    Stack<Type>::Stack(Stack &&other) noexcept {
        MAX_SIZE = other.MAX_SIZE;
        index = other.index;
        arr = other.arr;
        other.arr = nullptr;
    }

    template<class Type>
    Stack<Type> &Stack<Type>::operator=(const Stack<Type> &other) {
        if (this == &other) {
            return *this;
        }
        MAX_SIZE = other.MAX_SIZE;
        index = other.index;

        Type *new_arr = new Type(other.MAX_SIZE);
        for (int i = 0; i <= other.index; ++i) {
            new_arr[i] = other.arr[i];
        }
        delete[] arr;
        arr = new_arr;
        return *this;
    }

    template<class Type>
    Stack<Type> &Stack<Type>::operator=(Stack<Type> &&other) noexcept {
        if (this == &other) {
            return *this;
        }
        MAX_SIZE = other.MAX_SIZE;
        index = other.index;

        delete[] arr;
        arr = other.arr;
        other.arr = nullptr;
        return *this;
    }

    template<class Type>
    void Stack<Type>::push(const Type &element) {
        if (index + 1 == MAX_SIZE - 1) {
            this->realloc();
        }
        arr[++index] = element;
    }

//    template<class Type>
//    void Stack<Type>::push(const Type &&element) {
//        if (index + 1 == MAX_SIZE - 1) {
//            this->realloc();
//        }
//        arr[++index] = element;
//        element = nullptr;
//    }

//    template<class Type>
//    void Stack<Type>::pop() {
//        if (index == 0) {
//            return;
//        }
//        delete arr[index];
//        --index;
//    }

//    template<class Type>
//    Type Stack<Type>::top() {
//        return arr[index];
//    }
}