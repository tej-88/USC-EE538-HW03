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

TEST(WordHistogram, SingleWord) {
    std::string input = "he";
    std::map<std::string, int> actual = WordHistogram(input);
    std::map<std::string, int> expected = {{"he", 1}};
    EXPECT_EQ(expected, actual);
}

TEST(WordHistogram, DuplicateWords) {
    std::string input = "he,he";
    std::map<std::string, int> actual = WordHistogram(input);
    std::map<std::string, int> expected = {{"he", 2}};
    EXPECT_EQ(expected, actual);
}

TEST(WordHistogram, UniqueWords) {
    std::string input = "he,yo,";
    std::map<std::string, int> actual = WordHistogram(input);
    std::map<std::string, int> expected = {{"he", 1}, {"yo", 1}};
    EXPECT_EQ(expected, actual);
}

TEST(WordHistogram, LastWord) {
    std::string input = "he,yo";
    std::map<std::string, int> actual = WordHistogram(input);
    std::map<std::string, int> expected = {{"he", 1}, {"yo", 1}};
    EXPECT_EQ(expected, actual);
}