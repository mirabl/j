/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void rec(TreeNode *root, int& res, int cur) {
        if (!root) {
            return;
        }
        
        cur = 2 * cur + root->val;
        if (!root->left && !root->right) {
            res += cur;
        }
        rec(root->left, res, cur);
        rec(root->right, res, cur);
        
    }
    
    
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        rec(root, res, 0);
        return res;
    }
};
