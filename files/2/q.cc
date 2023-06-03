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

// Removes from the front of the queue. If the queue is empty, return false,
// otherwise true.
bool Queue::Dequeue() {
    if (IsEmpty()) {
        return false;
    }
    else {
        v_.erase(v_.begin());
        return true;
    }
}

// Returns true if the queue is empty.
bool Queue::IsEmpty() {
    return v_.empty();
}