#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.

// Copy constructor.
Queue::Queue(const Queue& rhs) : v_(rhs.v_) {
}