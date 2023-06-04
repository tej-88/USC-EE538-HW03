#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(LessOperator, TrueOutput) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 2;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    EXPECT_TRUE(a < b);
}

TEST(LessOperator, FalseOutput) {
    std::string name_a = "A";
    int grade_a = 10;
    std::string name_b = "B";
    int grade_b = 2;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    EXPECT_FALSE(a < b);
}

//-----------------------------------------------------------------------------
TEST(MoreOperator, TrueOutput) {
    std::string name_a = "A";
    int grade_a = 10;
    std::string name_b = "B";
    int grade_b = 2;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    EXPECT_TRUE(a > b);
}

TEST(MoreOperator, FalseOutput) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 2;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    EXPECT_FALSE(a > b);
}

//-----------------------------------------------------------------------------
TEST(EqualOperator, TrueOutput) {
    std::string name_a = "A";
    int grade_a = 10;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    EXPECT_TRUE(a == b);
}

TEST(EqualOperator, FalseOutput) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    EXPECT_FALSE(a == b);
}