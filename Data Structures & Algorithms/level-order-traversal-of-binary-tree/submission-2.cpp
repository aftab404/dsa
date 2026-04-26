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
  vector<vector<int>> levelOrder(TreeNode* root) {
    queue<pair<int, TreeNode*>> q;
    q.emplace(0, root);

    vector<int> lvl;
    vector<vector<int>> res;
    int curr_lvl = 0;

    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      if (node.second) {
        if (node.first == curr_lvl) {
          lvl.push_back(node.second->val);
        } else {
          res.push_back(lvl);
          lvl.clear();
          lvl.push_back(node.second->val);
          curr_lvl = node.first;
        }

        q.emplace(curr_lvl + 1, node.second->left);
        q.emplace(curr_lvl + 1, node.second->right);
      }
    }

    if (!lvl.empty()) res.push_back(lvl);
    return res;
  }
};
