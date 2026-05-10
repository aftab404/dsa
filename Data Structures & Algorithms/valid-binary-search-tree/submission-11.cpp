/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    queue<tuple<TreeNode*, int, int>> q;
    if (root) {
      q.emplace(root->left, INT_MIN, root->val);
      q.emplace(root->right, root->val, INT_MAX);
    } else {
      return true;
    }

    while (!q.empty()) {
      auto [node, min, max] = q.front();
      q.pop();

      if (node) {
        if (node->val <= min || node->val >= max) return false;
        q.emplace(node->left, min, node->val);
        q.emplace(node->right, node->val, max);
      }
    }

    return true;
  }
};
