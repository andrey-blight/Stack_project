#include "include/Stack.h"
#include <gtest/gtest.h>

using namespace stack_namespace;

TEST(Long_arithmetic, append_200_and_get_top) {
    Stack<int> s;
    for (int i = 0; i < 200; ++i) {
        s.push(i);
    }
    EXPECT_EQ(s.top(), 199);
}

TEST(Long_arithmetic, top_from_empty) {
    Stack<int> s;
    EXPECT_THROW(s.top(), std::invalid_argument);
}

TEST(Long_arithmetic, pop_from_empty) {
    Stack<int> s;
    for (int i = 0; i < 110; ++i) {
        s.push(1);
    }
    for (int i = 0; i < 110; ++i) {
        s.pop();
    }
    EXPECT_THROW(s.pop(), std::invalid_argument);
}


TEST(Long_arithmetic, create_from_another_stack) {
    Stack<int> first;
    first.push(1);
    Stack<int> second(first);
    EXPECT_EQ(second.top(), 1);
}

TEST(Long_arithmetic, create_using_eq) {
    Stack<int> first;
    first.push(1);
    Stack<int> second;
    second = second;
    second = first;
    EXPECT_EQ(second.top(), 1);
}

TEST(Long_arithmetic, create_using_rv) {
    Stack<int> first;
    first.push(1);
    Stack<int> second(std::move(first));
    EXPECT_EQ(second.top(), 1);
}

TEST(Long_arithmetic, create_from_another_stack_rv) {
    Stack<int> second{Stack<int>()};
    second.push(1);
    EXPECT_EQ(second.top(), 1);
}

TEST(Long_arithmetic, create_from_eq_rv) {
    Stack<int> second;
    second = Stack<int>();
    second.push(1);
    EXPECT_EQ(second.top(), 1);
}

//TEST(Long_arithmetic, create_from_another_stack) {
//    Stack<int> first;
//    first.pop();
//    for (int i = 0; i < 110; ++i) {
//        first.push(1);
//    }
//    first.push(2);
//    Stack<int> second(first);
//    second.pop();
//    EXPECT_EQ(second.top(), 1);
//}
