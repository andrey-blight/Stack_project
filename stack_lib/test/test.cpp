#include "include/Stack.h"
#include <gtest/gtest.h>

using namespace stack_namespace;

TEST(Long_arithmetic, delete_zeroes) {
    Stack<int> a;
    a.push(1);

    EXPECT_EQ(a.top(), 1);
}
