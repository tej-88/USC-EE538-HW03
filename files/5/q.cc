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