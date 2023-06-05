#include "q.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Already implemented. No need to change!
void DeleteMemory(BinaryTreeNode *root) {
  if (root == nullptr) {
    return;
  }

  DeleteMemory(root->left);
  DeleteMemory(root->right);
  delete root;
}

//-----------------------------------------------------------------------------
// Implement the following functions.
//-----------------------------------------------------------------------------
//
// It iterates through the nodes in preorder, and each time it visits the node
// it puts that node at the end of the output vector. It uses a helper
// function.
std::vector<int> BinaryTree::PreOrder() {
  std::vector<int> pre_vec;
  PreOrder_Helper(root_, pre_vec);
  return pre_vec;
}

// A helper function for Preorder.
void BinaryTree::PreOrder_Helper(BinaryTreeNode *root, std::vector<int> &v) {
  if (root == nullptr) {
    return;
  }
  else {
    v.push_back(root->val);
    PreOrder_Helper(root->left, v);
    PreOrder_Helper(root->right, v);
    return;
  }
}

// Returns the number of nodes in the tree. It uses size_helper.
int BinaryTree::size() {
  int num_nodes = 0;
  size_helper(root_, num_nodes);
  return num_nodes;
}

// A helper function for size()
void BinaryTree::size_helper(BinaryTreeNode *root, int &counter) {
  if (root == nullptr) {
    return;
  }
  else {
    counter++;
    size_helper(root->left, counter);
    size_helper(root->right, counter);
    return;
  }
}

// Returns the height of the tree. It uses GetHeight_Helper.
int BinaryTree::GetHeight() {
  int current_level = 0;
  int height = 0;
  GetHeight_Helper(root_, current_level, height);
  return height;
}

void BinaryTree::GetHeight_Helper(BinaryTreeNode *root, int current_level,
                      int &max_height) {
                        if (root == nullptr) {
                          if (current_level > max_height) {
                            max_height = current_level;
                          }
                          return;
                        }
                        else {
                          current_level++;
                          GetHeight_Helper(root->left, current_level, max_height);
                          GetHeight_Helper(root->right, current_level, max_height);
                          return;
                        }
                      }

// Assuming we have a complete tree with at least i nodes, it returns the path
// from the root to a given node index in the tree.
//
// Examples:
//
// i = 0
// Output: Empty vector.
//
// i = 1
// Output: {Direction::kLeft}
//
// i = 10
// Output: {Direction::kLeft, Direction::kRight, Direction::kRight}
// Explanation: Draw a diagram of a complete tree with 10 nodes. Then follow
// the path from the root to the node indexed 10. You will see that you should
// first go left, the right, then another right.
std::vector<Direction> BinaryTree::GetPathToIthElement(int i) {
  std::vector<Direction> result;
  if (i == 0) {
    return result;
  }
  else {
    while (i > 0) {
      if ((i % 2) == 0) {
        result.push_back(Direction::kRight);
      }
      else {
        result.push_back(Direction::kLeft);
      }
      i = GetParentIndex(i);
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
}

// Note that this function is outside of the BinaryTree class.
// Returns true if the given binary tree with the given root is a Binary Search
// Tree. If the tree was empty, it returns true.
// You can assume that there are no duplicate values in the given input tree and
// any child if it exists, has a non-negative value.
bool IsBST(BinaryTreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  else {
    BinaryTreeNode *left_ptr = root->left;
    BinaryTreeNode *right_ptr = root->right;
    if ((left_ptr == nullptr) && (right_ptr == nullptr)) {
      return true;
    }
    else if (left_ptr == nullptr) {
      if ((root->val) < (right_ptr->val)) {
        return IsBST(right_ptr);
      }
      else {
        return false;
      }
    }
    else if (right_ptr == nullptr) {
      if ((root->val) > (left_ptr->val)) {
        return IsBST(left_ptr);
      }
      else {
        return false;
      }
    }
    else {
      if (((root->val) > (left_ptr->val)) && ((root->val) < (right_ptr->val))){
        return (IsBST(left_ptr) && IsBST(right_ptr));
    }
  }
}