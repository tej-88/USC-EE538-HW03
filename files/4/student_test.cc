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

TEST(GetBackPointer, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_NE(l.GetBackPointer(), nullptr);
}

//-----------------------------------------------------------------------------
TEST(GetIthPointer, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_EQ(l.GetIthPointer(1), nullptr);
}

TEST(GetIthPointer, ValidInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_NE(l.GetIthPointer(1), nullptr);
    EXPECT_EQ(l.GetIthPointer(1)->val, 2);
}

TEST(GetIthPointer, InvalidInput) {
    std::vector<int> v = {1};
    SinglyLinkedList l(v);
    EXPECT_EQ(l.GetIthPointer(1), nullptr);
}

//-----------------------------------------------------------------------------
TEST(Operator, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_EQ(l[1], -1);
}

TEST(Operator, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_EQ(l[1], 2);
}

//-----------------------------------------------------------------------------
TEST(Print, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    l.print();
}

TEST(Print, EmptyInput) {
    SinglyLinkedList l;
    l.print();
}

//-----------------------------------------------------------------------------
TEST(ConvertToVector, EmptyInput) {
    SinglyLinkedList l;
    std::vector<int> expected;
    EXPECT_EQ(l.convert_to_vector(), expected);
}

TEST(ConvertToVector, NonEmptyInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(l.convert_to_vector(), expected);
}

//-----------------------------------------------------------------------------
TEST(Erase, EmptyInput) {
    SinglyLinkedList l;
    EXPECT_EQ(l.erase(1), nullptr);
}

TEST(Erase, FirstElementMultiInput) {
    std::vector<int> v = {1, 2};
    SinglyLinkedList l(v);
    EXPECT_NE(l.erase(1), nullptr);
}

TEST(Erase, FirstElementSingleInput) {
    std::vector<int> v = {1};
    SinglyLinkedList l(v);
    EXPECT_NE(l.erase(0), nullptr);
}

TEST(Erase, OutOfRange) {
    std::vector<int> v = {1};
    SinglyLinkedList l(v);
    EXPECT_EQ(l.erase(10), nullptr);
}

//-----------------------------------------------------------------------------
TEST(RemoveDuplicates, EmptyInput) {
    SinglyLinkedList l;
    l.remove_duplicates();
    std::vector<int> expected;
    EXPECT_EQ(l.convert_to_vector(), expected);
}

TEST(RemoveDuplicates, SingleInput) {
    std::vector<int> v = {1};
    SinglyLinkedList l(v);
    l.remove_duplicates();
    std::vector<int> expected = {1};
    EXPECT_EQ(l.convert_to_vector(), expected);
}

TEST(RemoveDuplicates, UniqueInputs) {
    std::vector<int> v = {1, 2, 3, 4};
    SinglyLinkedList l(v);
    l.remove_duplicates();
    std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(l.convert_to_vector(), expected);
}