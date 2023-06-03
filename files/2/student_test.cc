#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(CopyConstructor, EmptyInput) {
    Queue s;
    Queue r(s);
    EXPECT_EQ(r.IsEmpty(), s.IsEmpty());
    EXPECT_EQ(r.Front(), s.Front());
}
