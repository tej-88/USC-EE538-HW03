
#include <iostream>
#include <string>
#include <vector>

// TODO: Implement the functions that are specified below in the .cc file.

//-----------------------------------------------------------------------------
// The following are given. No need to change them.
//-----------------------------------------------------------------------------
class BinaryTree;
// This class is given, no need to change it.
struct BinaryTreeNode {
  int val;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  BinaryTreeNode(int x, BinaryTreeNode *left_ptr, BinaryTreeNode *right_ptr)
      : val(x), left(left_ptr), right(right_ptr) {}
};

// An enum class representing the direction. You don't need to modify this.
enum class Direction { kLeft, kRight };
// Used in the destructor. No need to change.
void DeleteMemory(BinaryTreeNode *root);

// A class representing a Binary Tree. Complete the functions that are asked
// below. We assume that any child if exists, has a non-negative value.
class BinaryTree {
 public:
  //-----------------------------------------------------------------------------
  // The following are given. No need to change them.
  // You will need to use the parameterized constructor in your test. See below.
  //-----------------------------------------------------------------------------
  // Non-parameterized Constructor is already implemented.
  BinaryTree() : root_(nullptr) {}

  // Returns the index of the parent of the given node index. You don't need to
  // modify this.
  int GetParentIndex(int i) {
    if (i == 0) {
      return -1;
    }
    return (i - 1) / 2;
  }

  // Parameterized constructor is already implemented. You don't need to modify
  // this.
  //
  // HOWEVER, YOU DO NEED TO USE THIS FUNCTION FOR YOUR TEST.
  // This constructor takes a vector of elements and creates a Binary tree from
  // it. If an element at index i is negative, it assumes that that the i(th)
  // element in the tree does not exists in the tree. Otherwise, it puts it as
  // the i(th) node in the tree where the root has index 0, the left child of
  // the root is indexed 1 and the right child of the root is indexed 2 and so
  // on.
  //
  // Examples:
  //
  // v = {1, 2, 3}:
  // This is a tree whose root is 1, the left child is 2, and the right child
  // is 3.
  //
  // v = {1, -1, 3}: This is a tree whose root is 1, the left
  // child does not exist, and the right child is 3.
  //
  // v = {1, -1, 3}: This is a
  // tree whose root is 1, the left child does not exist, and the right child
  // is 3.
  //
  // v = {15, 5, 14, -1, 1, -1, 12}, represents the tree shown below:
  //        15
  //       /   \
  //     5     14
  //      \      \
  //       1      12
  BinaryTree(const std::vector<int> &v) {
    if (v.empty()) {
      root_ = nullptr;
      return;
    }

    root_ = new BinaryTreeNode(v[0]);

    for (int i = 1; i < v.size(); i++) {
      auto e = v[i];

      if (e >= 0) {
        // First, get the parent index:
        auto parent_index = GetParentIndex(i);

        // Now go to the parent node in the tree:
        auto parent_node = GetIthPointer(parent_index);

        auto child = new BinaryTreeNode(e);
        if (i % 2 == 0) {
          parent_node->right = child;
        } else {
          parent_node->left = child;
        }
      }
    }
  }

  // This function is already implemented. No need to change it.
  // You don't need to use this function.
  // Returns a pointer to the i(th) node in the tree. Remember that we start
  // indexing the nodes from the root which has index 0.
  BinaryTreeNode *GetIthPointer(int i) {
    auto path = GetPathToIthElement(i);

    BinaryTreeNode *current_node = root_;
    for (auto d : path) {
      if (!current_node) {
        return nullptr;
      }

      if (d == Direction::kLeft) {
        current_node = current_node->left;
      } else {
        current_node = current_node->right;
      }
    }
    return current_node;
  }
  // Already implemented. No need to change.
  ~BinaryTree() { DeleteMemory(root_); }

  //-----------------------------------------------------------------------------
  // Implement the following functions.
  //-----------------------------------------------------------------------------
  //
  // It iterates through the nodes in preorder, and each time it visits the node
  // it puts that node at the end of the output vector. It uses a helper
  // function.
  std::vector<int> PreOrder();
  // A helper function for Preorder.
  void PreOrder_Helper(BinaryTreeNode *root, std::vector<int> &v);

  // Returns the number of nodes in the tree. It uses size_helper.
  int size();

  // A helper function for size()
  void size_helper(BinaryTreeNode *root, int &counter);

  // Returns the height of the tree. It uses GetHeight_Helper.
  int GetHeight();
  void GetHeight_Helper(BinaryTreeNode *root, int current_level,
                        int &max_height);

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
  std::vector<Direction> GetPathToIthElement(int i);

  BinaryTreeNode *root_;
};

// Note that this function is outside of the BinaryTree class.
// Returns true if the given binary tree with the given root is a Binary Search
// Tree. If the tree was empty, it returns true.
// You can assume that there are no duplicate values in the given input tree and
// any child if it exists, has a non-negative value.
bool IsBST(BinaryTreeNode *root);

//-----------------------------------------------------------------------------
