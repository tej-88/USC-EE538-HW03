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
    int grade_a = 1;
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

//-----------------------------------------------------------------------------
TEST(GetParent, OutOfRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);
    Student expected;

    EXPECT_EQ(h.GetParent(3), expected);
}

TEST(GetParent, WithinRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);
    Student expected = b;

    EXPECT_EQ(h.GetParent(1), expected);
}

TEST(GetParent, Root) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);
    Student expected;

    EXPECT_EQ(h.GetParent(0), expected);
}

//-----------------------------------------------------------------------------
TEST(GetLeft, OutOfRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);
    Student expected;

    EXPECT_EQ(h.GetLeft(1), expected);
}

TEST(GetLeft, WithinRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);
    Student expected = a;

    EXPECT_EQ(h.GetLeft(0), expected);
}
