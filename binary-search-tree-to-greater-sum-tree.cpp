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
    void r(TreeNode* root, int& c) {
        if (!root) {
            return;
        }
        r(root->right, c);
        c += root->val;
        root->val = c;
        r(root->left, c);
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
        int c = 0;
        r(root, c);
        return root;
    }
};
