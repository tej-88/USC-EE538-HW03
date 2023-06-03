#ifndef SOL_7_Q
#define SOL_7_Q
#include <climits>
#include <iostream>
#include <string>
#include <vector>
// TODO: Implement the functions that are specified below in the .cc file.

class Student {
 public:
  //-----------------------------------------------------------------------------
  // Already implemented functions.
  //-----------------------------------------------------------------------------
  // Used by GoogleTest. No need to change it.
  // See here for more info: https://www.youtube.com/watch?v=JJqRlSTQlh4&t=1806s
  friend void PrintTo(const Student& student, std::ostream* os) {
    *os << student.DebugString();
  }

  // This function will be called by testing::PrintToString.
  // Used by GoogleTest. No need to change it.
  // See here for more info: https://www.youtube.com/watch?v=JJqRlSTQlh4&t=1806s
  std::string DebugString() const {
    std::string result;
    return result + "name: " + name + ", grade: " + std::to_string(grade) +
           "\n";
  }

  //-----------------------------------------------------------------------------
  // Implement the following functions.
  //-----------------------------------------------------------------------------
  // Parameterized constructor
  Student(std::string name, int grade);

  // Non-parameterized constructor. Sets the default value for name to "NO_NAME"
  // and grade to INT_MIN.
  Student();

  // Copy constructor.
  Student(const Student& rhs);

  // The following operators are overloaded. They only compare the grade part of
  // the class with other objects.

  // Returns true if grade is less than the grade of other Student objects and
  // false otherwise.
  bool operator<(const Student& rhs) const;

  // Returns true if grade is greater than the grade of other Student objects
  // and false otherwise.
  bool operator>(const Student& rhs) const;

  // Returns true if grade is equal to the grade of other Student objects and
  // false otherwise.
  bool operator==(const Student& rhs) const;

  std::string name;
  int grade;
};
//-----------------------------------------------------------------------------
// Already implemented functions.
//-----------------------------------------------------------------------------
// Used by GoogleTest. No need to change it.
std::ostream& operator<<(std::ostream& os, const Student& s);
//-----------------------------------------------------------------------------

//
//-----------------------------------------------------------------------------
// Implement StudentMaxHeap class
//-----------------------------------------------------------------------------
// A Max Heap that contains objects of type Student.
// We compare the students only based on their grade, not their names. That
// means the student with the highest grade should always be at the top of the
// heap.
class StudentMaxHeap {
 public:
  // Non-parameterized constructor: already defined. No need to modify.
  StudentMaxHeap() {}

  // Parameterized constructor: creates a max heap from the given input.
  StudentMaxHeap(std::vector<Student>& input);

  // Returns the parent of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student GetParent(int i);

  // Returns the left child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student GetLeft(int i);

  // Returns the right child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student GetRight(int i);

  // Returns the index of the parent of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int GetParentIndex(int i);

  // Returns the index of the left child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int GetLeftIndex(int i);

  // Returns the index of the right child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int GetRightIndex(int i);

  // Returns the index of the largest child of a node given its index in the
  // tree. Returns INT_MAX if unsuccessful.
  int GetLargestChildIndex(int i);

  // Returns true if the heap is empty and false otherwise.
  bool empty() { return data_.empty(); };

  // Returns the size of the heap.
  int size() { return data_.size(); }

  // Returns the top of the heap. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student top();

  // Adds a new Student to the heap.
  void push(const Student& student);

  // Removes the top. Returns
  // true if successful and false otherwise.
  bool pop();

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void TrickleUp(int i);

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void TrickleDown(int i);

  // Converts the given input into a max heap and stores that into data_.
  void ConvertToHeap(const std::vector<Student>& input);

  // Already implemented. No need to modify.
  std::vector<Student> GetData() { return data_; }

 private:
  std::vector<Student> data_;
};

// Sorts the given input vector of students in place. The sort is in ascending
// order based on the grades.
void HeapSort(std::vector<Student>& input);

#endif /* SOL_7_Q */
