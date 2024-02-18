#ifndef STACK_LIBRARY_H
#define STACK_LIBRARY_H
namespace stack_namespace {

    template<class Type>
    class Stack {
    private:
        unsigned long long index{};
        Type *arr;
        unsigned long long MAX_SIZE{};

        void realloc(){
            MAX_SIZE *= 2;

            Type *new_arr = new Type(MAX_SIZE);
            for (int i = 0; i <= index; ++i) {
                new_arr[i] = arr[i];
            }

            delete[] arr;
            arr = new_arr;
        }

    public:
        Stack(){
            MAX_SIZE = 100;
            arr = new Type(MAX_SIZE);
            index = 0;
        }

        ~Stack(){
            delete[] arr;
        }

        Stack(Stack const &other);

        Stack(Stack &&other)

        noexcept;

        Stack &operator=(Stack const &other);

        Stack &operator=(Stack &&other)

        noexcept;

        void push(const Type &element);

        void push(const Type &&element){
            if (index + 1 == MAX_SIZE - 1) {
                this->realloc();
            }
            arr[++index] = element;
//            element = nullptr;
        }

        void pop() {
            if (index == 0) {
                return;
            }
//            delete arr[index];
            --index;
        }

        Type top(){
            return arr[index];
        }
    };


}

#endif
