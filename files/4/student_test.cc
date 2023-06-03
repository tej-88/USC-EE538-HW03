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

TEST(ParamConstructor, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_EQ(l.size_, 2);
    EXPECT_NE(l.head_, nullptr);
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 2);
}

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(CopyConstructor, EmptyInput) {
    SinglyLinkedList v;
    SinglyLinkedList l(v);
    EXPECT_EQ(l.size_, v.size_);
    EXPECT_EQ(l.head_, v.head_);
}

TEST(CopyConstructor, NonEmptyInput) {
    std::vector<int> v = {1, 2}
    SinglyLinkedList s(v);
    SinglyLinkedList l(s);
    EXPECT_EQ(l.size_, 2);
    EXPECT_NE(l.head_, nullptr);
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 2);
}