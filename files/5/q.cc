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

// Returns true if grade is equal to the grade of other Student objects and
// false otherwise.
bool Student::operator==(const Student& rhs) const {
  return (grade == rhs.grade);
}


//-----------------------------------------------------------------------------
// Implement StudentMaxHeap class
//-----------------------------------------------------------------------------

// Returns the parent of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetParent(int i) {
  int parent_idx = GetParentIndex(i);
  if (parent_idx == INT_MAX) {
    Student tmp;
    return tmp;
  }
  else {
    return data_[parent_idx];
  }
}

// Returns the left child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetLeft(int i) {
  int left_child_idx = GetLeftIndex(i);
  if (left_child_idx == INT_MAX) {
    Student tmp;
    return tmp;
  }
  else {
    return data_[left_child_idx];
  }
}

// Returns the right child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetRight(int i) {
  int right_child_idx = GetRightIndex(i);
    if (right_child_idx == INT_MAX) {
      Student tmp;
      return tmp;
    }
    else {
      return data_[right_child_idx];
    }
}