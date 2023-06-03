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

//-----------------------------------------------------------------------------
TEST(Empty, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_TRUE(l.empty());
}

TEST(Empty, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_FALSE(l.empty());
}

//-----------------------------------------------------------------------------
TEST(Size, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_EQ(l.size(), 0);
}

TEST(Size, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_EQ(l.size(), 2);
}

//-----------------------------------------------------------------------------
TEST(Head, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_EQ(l.head(), nullptr);
}

TEST(Head, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_NE(l.head(), nullptr);
}

//-----------------------------------------------------------------------------
TEST(PushBack, Input) {
    SinglyLinkedList l;
    EXPECT_EQ(l.push_back(1), void);
    EXPECT_EQ(l.size(), 1);
    EXPECT_NE(l.head(), nullptr);
}

//-----------------------------------------------------------------------------
TEST(Pop_Back, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_FALSE(l.pop_back());
}

TEST(Pop_Back, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_TRUE(l.pop_back());
    EXPECT_EQ(l.size(), 1);
}

//-----------------------------------------------------------------------------
TEST(Back, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_EQ(l.back(), -1);
}

TEST(Back, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_EQ(l.back(), 2);
}

//-----------------------------------------------------------------------------
TEST(GetBackPointer, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_EQ(l.GetBackPointer(), nullptr);
}