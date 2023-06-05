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

//-----------------------------------------------------------------------------
TEST(GetRight, OutOfRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);
    Student expected;

    EXPECT_EQ(h.GetRight(0), expected);
}

TEST(GetRight, WithinRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;
    std::string name_c = "C";
    int grade_c = 20;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    Student c(name_c, grade_c);

    std::vector<Student> student_vec = {a, b, c};
    StudentMaxHeap h(student_vec);
    Student expected = b;

    EXPECT_EQ(h.GetRight(0), expected);
}

//-----------------------------------------------------------------------------
TEST(GetParentIndex, OutOfRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetParentIndex(3), INT_MAX);
}

TEST(GetParentIndex, WithinRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetParentIndex(1), 0);
}

TEST(GetParentIndex, Root) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetParentIndex(0), INT_MAX);
}

//-----------------------------------------------------------------------------
TEST(GetLeftIndex, OutOfRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetLeftIndex(1), INT_MAX);
}

TEST(GetLeftIndex, WithinRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetLeftIndex(0), 1);
}

//-----------------------------------------------------------------------------
TEST(GetRightIndex, OutOfRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetRightIndex(1), INT_MAX);
}

TEST(GetRightIndex, WithinRange) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;
    std::string name_c = "C";
    int grade_c = 20;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    Student c(name_c, grade_c);

    std::vector<Student> student_vec = {a, b, c};
    StudentMaxHeap h(student_vec);
    Student expected = b;

    EXPECT_EQ(h.GetRightIndex(0), 2);
}

//-----------------------------------------------------------------------------
TEST(GetLargestChildIndex, NoChild) {
    std::string name_a = "A";
    int grade_a = 1;
    
    Student a(name_a, grade_a);

    std::vector<Student> student_vec = {a};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetLargestChildIndex(0), INT_MAX);
}

TEST(GetLargestChildIndex, OneChild) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetLargestChildIndex(0), 1);
}

TEST(GetLargestChildIndex, TwoChild) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;
    std::string name_c = "C";
    int grade_c = 20;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    Student c(name_c, grade_c);

    std::vector<Student> student_vec = {a, b, c};
    StudentMaxHeap h(student_vec);

    EXPECT_EQ(h.GetLargestChildIndex(0), 2);
}

//-----------------------------------------------------------------------------
TEST(Top, EmptyHeap) {
    StudentMaxHeap h;
    Student expected;
    EXPECT_EQ(h.top(), expected);
}

TEST(Top, NonEmptyHeap) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;
    std::string name_c = "C";
    int grade_c = 20;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    Student c(name_c, grade_c);

    std::vector<Student> student_vec = {a, b, c};
    StudentMaxHeap h(student_vec);
    Student expected = c;
    EXPECT_EQ(h.top(), expected);
}

//-----------------------------------------------------------------------------
TEST(Push, EmptyHeap) {
    std::string name_a = "A";
    int grade_a = 1;
    Student a(name_a, grade_a);

    StudentMaxHeap h;
    std::vector<Student> expected = {a};
    h.push(a);

    EXPECT_EQ(h.GetData(), expected);
}

TEST(Push, NonEmptyHeap) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);

    std::vector<Student> student_vec = {a, b};
    StudentMaxHeap h(student_vec);
    
    std::string name_c = "C";
    int grade_c = 20;
    Student c(name_c, grade_c);

    h.push(c);
    std::vector<Student> expected = {c, a, b};
    EXPECT_EQ(h.GetData(), expected);
}

//-----------------------------------------------------------------------------
TEST(Pop, EmptyHeap) {
    StudentMaxHeap h;
    std::vector<Student> expected;
    EXPECT_FALSE(h.pop());
    EXPECT_EQ(h.GetData(), expected);
}

TEST(Pop, NonEmptyHeap) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;
    std::string name_c = "C";
    int grade_c = 20;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    Student c(name_c, grade_c);

    std::vector<Student> student_vec = {a, b, c};
    StudentMaxHeap h(student_vec);
    

    std::vector<Student> expected = {b, a};
    EXPECT_TRUE(h.pop());
    EXPECT_EQ(h.GetData(), expected);
}

//-----------------------------------------------------------------------------
TEST(ConvertToHeap, EmptyInput) {
    StudentMaxHeap h;
    std::vector<Student> expected;
    h.ConvertToHeap(expected);
    EXPECT_EQ(h.GetData(), expected);
}

TEST(ConvertToHeap, NonEmptyHeap) {
    std::string name_a = "A";
    int grade_a = 1;
    std::string name_b = "B";
    int grade_b = 10;
    std::string name_c = "C";
    int grade_c = 20;

    Student a(name_a, grade_a);
    Student b(name_b, grade_b);
    Student c(name_c, grade_c);

    std::vector<Student> student_vec = {a, b, c};
    StudentMaxHeap h;
    

    std::vector<Student> expected = {c, a, b};
    h.ConvertToHeap(student_vec);
    EXPECT_EQ(h.GetData(), expected);
}