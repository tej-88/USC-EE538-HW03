#include "q.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

//-----------------------------------------------------------------------------
// Used by Google test. No need to change this!
//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Student& s) {
  return os << s.DebugString();
}
//-----------------------------------------------------------------------------


// Parameterized constructor
Student::Student(std::string name, int grade) : name(name), grade(grade) {

}

// Non-parameterized constructor. Sets the default value for name to "NO_NAME"
// and grade to INT_MIN.
Student::Student() : name("NO_NAME"), grade(INT_MIN) {

}

// Copy constructor.
Student::Student(const Student& rhs) : name(rhs.name), grade(rhs.grade) {

}

// The following operators are overloaded. They only compare the grade part of
// the class with other objects.

// Returns true if grade is less than the grade of other Student objects and
// false otherwise.
bool Student::operator<(const Student& rhs) const {
  return (grade < rhs.grade);
}

// Returns true if grade is greater than the grade of other Student objects
// and false otherwise.
bool Student::operator>(const Student& rhs) const {
  return (grade > rhs.grade);
}