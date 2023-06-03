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
TEST(BinaryTreeTest, Test1) {}
