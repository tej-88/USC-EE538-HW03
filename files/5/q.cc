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

// Parameterized constructor: creates a max heap from the given input.
StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input) {
  ConvertToHeap(input);
}

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

// Returns the index of the parent of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetParentIndex(int i) {
  int parent_idx = (i - 2) / 2;
  if ((parent_idx < 0) || (i >= size())) {
    return INT_MAX;
  }
  else {
    return parent_idx;
  }
}

// Returns the index of the left child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLeftIndex(int i) {
  int left_child_idx = (i * 2) + 1;
  if ((i < 0) || (left_child_idx >= size())) {
    return INT_MAX;
  }
  else {
    return left_child_idx;
  }
}

// Returns the index of the right child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetRightIndex(int i) {
  int right_child_idx = (i * 2) + 2;
  if ((i < 0) || (right_child_idx >= size())) {
    return INT_MAX;
  }
  else {
    return right_child_idx;
  }
}

// Returns the index of the largest child of a node given its index in the
// tree. Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLargestChildIndex(int i) {
  int left_child_idx = GetLeftIndex(i);
  int right_child_idx = GetRightIndex(i);
  
  if ((left_child_idx == INT_MAX) && (right_child_idx == INT_MAX)) {
    return INT_MAX;
  }
  else if (right_child_idx == INT_MAX) {
    return left_child_idx;
  }
  else {
    if (data_[left_child_idx] < data_[right_child_idx]) {
      return right_child_idx;
    }
    else {
      return left_child_idx;
    }
  }
}

// Returns the top of the heap. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::top() {
  if (empty()) {
    Student tmp;
    return tmp;
  }
  else {
    return data_[0];
  }
}

// Adds a new Student to the heap.
void StudentMaxHeap::push(const Student& student) {
  data_.push_back(student);
  TrickleUp(size() - 1);
  return;
}

// Removes the top. Returns
// true if successful and false otherwise.
bool StudentMaxHeap::pop() {
  if (empty()) {
    return false;
  }
  else {
    data_[0] = data_[size() - 1];
    data_.pop_back();
    TrickleDown(0);
    return true;
  }
}

// Performs trickle up. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleUp(int i) {
  if ((i < 0) || (i >= size())) {
    return;
  }
  else {
    int parent_idx = GetParentIndex(i);
    if (parent_idx == INT_MAX) {
      return;
    }
    else {
      Student parent = data_[parent_idx];
      Student child = data_[i];
      if (child < parent) {
        return;
      }
      else {
        data_[parent_idx] = child;
        data_[i] = parent;
        TrickleUp(parent_idx);
        return;
      }
    }
  }
}

// Performs trickle up. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleDown(int i) {
  if ((i < 0) || (i >= size())) {
    return;
  }
  else {
    int child_idx = GetLargestChildIndex(i);
    if (child_idx == INT_MAX) {
      return;
    }
    else {
      Student parent = data_[i];
      Student child = data_[child_idx];
      if (parent < child) {
        data_[i] = child;
        data_[child_idx] = parent;
        TrickleDown(child_idx);
        return;
      }
      else {
        return;
      }
    }
  }
}

// Converts the given input into a max heap and stores that into data_.
void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input) {
  for (const auto &x : input) {
    push(x);
  }
  return;
}