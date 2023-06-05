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