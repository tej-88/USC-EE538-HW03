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
