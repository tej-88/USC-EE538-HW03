#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(WordHistogram, EmptyInput) {
    std::string input;
    std::map<std::string, int> actual = WordHistogram(input);
    std::map<std::string, int> expected;
    EXPECT_EQ(expected, actual);
}