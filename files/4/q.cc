#include "q.h"

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
// Implement each function of `q.h` here.

// Write a new parameterized constructor that takes a vector as an input and
// crates a linked list based on that. Note that your constructor should
// assign a valid value for head_. Example:
// Input:  v = {1, 4, 5, 6, 10}
// The created list: 1->4->5->6->10, and head_ will point to the first node
// with value 1.
SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v) {
    if (v.empty()) {
        size_ = 0;
        head_ = nullptr;
    }
    else {
        for (const auto &x : v) {
            push_back(x);
        }
    }
}

// Copy constructor.
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs) {
    if (rhs.empty()) {
        size_ = 0;
        head_ = nullptr;
    }
    else {
        for (int i = 0; i < rhs.size_; i++) {
            push_back(rhs[i]);
        }
    }
}

// Returns true if the list is empty, false otherwise.
bool SinglyLinkedList::empty() {
    return (size_ == 0);
}

// Returns the current size of the list.
int SinglyLinkedList::size() {
    return size_;
}