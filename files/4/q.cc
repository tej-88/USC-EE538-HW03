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
    size_ = 0;
    if (v.empty()) {
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
    if (rhs.size_ == 0) {
        size_ = 0;
        head_ = nullptr;
    }
    else {
        ListNode *rhs_node_ptr = rhs.head_;
        while (rhs_node_ptr != nullptr) {
            push_back(rhs_node_ptr->val);
            rhs_node_ptr = rhs_node_ptr->next;
        }
    }
}

// Destructor
SinglyLinkedList::~SinglyLinkedList() {
    while (pop_back());
}

// Returns true if the list is empty, false otherwise.
bool SinglyLinkedList::empty() {
    return (size_ == 0);
}

// Returns the current size of the list.
int SinglyLinkedList::size() {
    return size_;
}

// Returns a pointer to the head of the list.
ListNode *SinglyLinkedList::head() {
    return head_;
}

// Insert i at the back of the list.
void SinglyLinkedList::push_back(int i) {
    if (empty()) {
        head_ = new ListNode(i);
        size_++;
        return;
    }
    else {
        ListNode *new_node_ptr = new ListNode(i);
        ListNode *back_node_ptr = GetBackPointer();
        back_node_ptr->next = new_node_ptr;
        size_++;
        return;
    }
}

// Removes an item from the back of the list. Returns true if it was
// successfull.
bool SinglyLinkedList::pop_back() {
    if (empty()) {
        return false;
    }
    else {
        ListNode *back_node_ptr = GetBackPointer();
        delete back_node_ptr;
        size_--;
        return true;
    }
}

// Returns the item in the back of the list. Returns -1 if empty.
int SinglyLinkedList::back() {
    if (empty()) {
        return -1;
    }
    else {
        ListNode *back_node_ptr = GetBackPointer();
        return back_node_ptr->val;
    }
}

// Returns a pointer to the back of the list.
ListNode *SinglyLinkedList::GetBackPointer() {
    return GetIthPointer(size() - 1);
}

// Returns a pointer to the i(th) element in the list. nullptr if it doesn't
// exist.
ListNode *SinglyLinkedList::GetIthPointer(int i) {
    if ((i < 0) || (i >= size())) {
        return nullptr;
    }
    else {
        ListNode *tmp_node_ptr = head();
        for (int a = 1; a <= i; a++) {
            tmp_node_ptr = tmp_node_ptr -> next;
        }
        return tmp_node_ptr;
    }
}

// Returns the i(th) element in the list. -1 if it doesn't exits.
int SinglyLinkedList::operator[](int i) {
    ListNode *i_node_ptr = GetIthPointer(i);

    if (i_node_ptr == nullptr) {
        return -1;
    }
    else {
        return i_node_ptr->val;
    }
}

 // Prints the items in the list.
void SinglyLinkedList::print() {
    for (int i = 0, s = size(); i < s; i++) {
        std::cout << operator[](i) << " ";
    }
    std::cout << std::endl;
    return;
}

// Write a function that converts the list into a vector. Example:
// The list: 1->4->5->6->10
// Output: a vector with value: {1, 4, 5, 6, 10}
std::vector<int> SinglyLinkedList::convert_to_vector() {
    std::vector<int> v;
    for (int i = 0, s = size(); i < s; i++) {
        v.push_back(operator[](i));
    }
    return v;
}

// Erases element i from the list if it exists and returns a pointer to item
// i-1. If item i doesn't exist, returns nullptr. The first item in the list
// has index 0.

// Example:
// Input: 1 -> 5 -> 10 ->20, i= 2.
// Output: 1 -> 5 -> 20, return value: a pointer to element 5.
ListNode *SinglyLinkedList::erase(int i) {
    if ((i < 0) || (i >= size())) {
        return nullptr;
    }
    else if (i == 0) {
        ListNode *tmp_node_ptr = head_;
        head_ = tmp_node_ptr->next;
        delete tmp_node_ptr;
        size_--;
        return head_;
    }
    else {
        ListNode *i_node_ptr = GetIthPointer(i);
        ListNode *i_prev_node_ptr = GetIthPointer(i - 1);
        i_prev_node_ptr->next = i_node_ptr->next;
        delete i_node_ptr;
        size_--;
        return i_prev_node_ptr;
    }
}

// Removes duplicate elements and only keeps the first one.
// Example:
// Input: 1 -> 5 -> 1 -> 20 -> 4 -> 5 -> 32
// Output: 1 -> 5 -> 20 -> 4 -> 32
void SinglyLinkedList::remove_duplicates() {
    if (size() <= 1) {
        return;
    }
    else {
        ListNode *tmp_node_ptr = head();
        std::unordered_set<int> tmp_set;
        int i = 0;

        while (tmp_node_ptr != nullptr) {
            int val = tmp_node_ptr->val; 
            auto set_iter = tmp_set.find(val);
            if (set_iter == tmp_set.end()) {
                tmp_set.insert(val);
                i++;        
            }
            else {
                tmp_node_ptr = erase(i);
            }
            tmp_node_ptr = tmp_node_ptr->next;
        }
        return;
    }
}