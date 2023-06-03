#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.

// Copy constructor.
Queue::Queue(const Queue& rhs) : v_(rhs.v_) {
}

// Inserts in the back of the queue.
bool Queue::Enqueue(int value) {
    v_.push_back(value);
    return true;
}