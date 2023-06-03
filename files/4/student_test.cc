#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(ParamConstructor, EmptyInput) {
    std::vector<int> v;
    SinglyLinkedList l(v);
    EXPECT_EQ(l.size_, 0);
    EXPECT_EQ(l.head_, nullptr);
}
