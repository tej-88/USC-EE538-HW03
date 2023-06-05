#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

// This function will be used by Google Test. No need to change it.
std::ostream& operator<<(std::ostream& os, const Direction& d) {
  return os << ((d == Direction::kLeft) ? "kLeft" : "kRight");
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(PreOrder, EmptyTree) {
  std::vector<int> vec;
  BinaryTree bt(vec);
  std::vector<int> expected;
  EXPECT_EQ(bt.PreOrder(), expected);
}

TEST(PreOrder, SingleNode) {
  std::vector<int> vec = {1};
  BinaryTree bt(vec);
  std::vector<int> expected = {1};
  EXPECT_EQ(bt.PreOrder(), expected);
}

TEST(PreOrder, MultipleNode) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
  BinaryTree bt(vec);
  std::vector<int> expected = {1, 2, 4, 8, 5, 3, 6, 7};
  EXPECT_EQ(bt.PreOrder(), expected);
}

TEST(PreOrder, MultipleMissingNode) {
  std::vector<int> vec = {15, 5, 14, -1, 1, -1, 12};
  BinaryTree bt(vec);
  std::vector<int> expected = {15, 5, 1, 14, 12};
  EXPECT_EQ(bt.PreOrder(), expected);
}

//-----------------------------------------------------------------------------
TEST(Size, EmptyTree) {
  std::vector<int> vec;
  BinaryTree bt(vec);
  EXPECT_EQ(bt.size(), 0);
}

TEST(Size, SingleNode) {
  std::vector<int> vec = {1};
  BinaryTree bt(vec);
  EXPECT_EQ(bt.size(), 1);
}

TEST(Size, MultipleNode) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
  BinaryTree bt(vec);
  EXPECT_EQ(bt.size(), 8);
}

TEST(Size, MultipleMissingNode) {
  std::vector<int> vec = {15, 5, 14, -1, 1, -1, 12};
  BinaryTree bt(vec);
  EXPECT_EQ(bt.size(), 5);
}

//-----------------------------------------------------------------------------
TEST(GetHeight, EmptyTree) {
  std::vector<int> vec;
  BinaryTree bt(vec);
  EXPECT_EQ(bt.GetHeight(), 0);
}

TEST(GetHeight, SingleNode) {
  std::vector<int> vec = {1};
  BinaryTree bt(vec);
  EXPECT_EQ(bt.GetHeight(), 1);
}

TEST(GetHeight, MultipleNode) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
  BinaryTree bt(vec);
  EXPECT_EQ(bt.GetHeight(), 4);
}

TEST(GetHeight, MultipleMissingNode) {
  std::vector<int> vec = {15, 5, 14, -1, 1, -1, 12};
  BinaryTree bt(vec);
  EXPECT_EQ(bt.GetHeight(), 3);
}

//-----------------------------------------------------------------------------
TEST(GetPathToIthElement, ZeroIndex) {
  BinaryTree bt;
  std::vector<Direction> expected;
  EXPECT_EQ(bt.GetPathToIthElement(0), expected);
}

TEST(GetPathToIthElement, OneIndex) {
  BinaryTree bt;
  std::vector<Direction> expected = {Direction::kLeft};
  EXPECT_EQ(bt.GetPathToIthElement(1), expected);
}

TEST(GetPathToIthElement, TwoIndex) {
  BinaryTree bt;
  std::vector<Direction> expected = {Direction::kRight};
  EXPECT_EQ(bt.GetPathToIthElement(2), expected);
}

TEST(GetPathToIthElement, EightIndex) {
  BinaryTree bt;
  std::vector<Direction> expected = {Direction::kLeft, Direction::kLeft, Direction::kRight};
  EXPECT_EQ(bt.GetPathToIthElement(8), expected);
}

TEST(GetPathToIthElement, ElevenIndex) {
  BinaryTree bt;
  std::vector<Direction> expected = {Direction::kRight, Direction::kLeft, Direction::kLeft};
  EXPECT_EQ(bt.GetPathToIthElement(11), expected);
}