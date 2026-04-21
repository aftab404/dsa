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
    int maxDepth(TreeNode* root) {
        stack<pair<int, TreeNode*>> stk;
        stk.push({0, root});
        int res = 0;

        while(!stk.empty()){
            auto parent = stk.top(); stk.pop();
            res = max(res, parent.first);

            if(parent.second){
                stk.push({parent.first + 1, parent.second->left});
                stk.push({parent.first + 1, parent.second->right});
            }
        }

        return res;


    }
};
