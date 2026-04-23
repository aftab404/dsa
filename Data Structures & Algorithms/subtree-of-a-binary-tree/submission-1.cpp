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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    stack<pair<TreeNode*, TreeNode*>> stk;

    stk.emplace(p, q);

    while (!stk.empty()) {
      auto top = stk.top();
      stk.pop();
      if (top.first == nullptr && top.second == nullptr) {
        continue;
      }
      if (top.first == nullptr && top.second != nullptr ||
          top.first != nullptr && top.second == nullptr) {
        return false;
      }
      if (top.first->val != top.second->val) {
        return false;
      }

      if (top.first && top.second) {
        stk.emplace(top.first->left, top.second->left);
        stk.emplace(top.first->right, top.second->right);
      }
    }

    return true;
  }

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    stack<TreeNode*> stk;

    stk.push(root);
    bool res = false;

    while (!stk.empty()) {
      TreeNode* top = stk.top();
      stk.pop();

      if (top) {
        if (top->val == subRoot->val) {
          res = isSameTree(top, subRoot);
          if(res) break;
        }

        stk.push(top->left);
        stk.push(top->right);
      }
    }

    return res;
  }
};
