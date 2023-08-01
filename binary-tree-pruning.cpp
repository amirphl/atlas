// https://leetcode.com/problems/binary-tree-pruning/
#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *pruneTree(TreeNode *root) {
    if (!root) {
      return 0;
    }
    if (!(root->left) && !(root->right)) {
      if (root->val == 0) {
        delete root;
        return 0;
      }
      return root;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == 0 && root->right == 0 && root->val == 0) {
      delete root;
      return 0;
    }
    return root;
  }
};
