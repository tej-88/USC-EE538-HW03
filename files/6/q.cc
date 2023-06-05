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