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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* parent = root;
        while(parent){
            if(p->val <= parent->val && q->val >= parent->val 
            || p->val >= parent->val && q->val <= parent->val) {
                return parent;
            }
            else {
                if(p->val >= parent->val && q->val >= parent->val){
                    parent = parent->right;
                }else{
                    parent = parent->left;
                }
            }
        }

        return parent;
    }
};
