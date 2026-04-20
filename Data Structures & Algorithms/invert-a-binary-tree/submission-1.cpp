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
  TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> stk;

    stk.push(root);

    while (!stk.empty()) {
      TreeNode* parent = stk.top();
      stk.pop();

      if (parent) {
        TreeNode* temp = parent->left;
        parent->left = parent->right;
        parent->right = temp;

        stk.push(parent->right);
        stk.push(parent->left);
      }
    }

    return root;
  }
};
