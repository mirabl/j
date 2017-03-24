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
    int m = 0;
    
    int rec(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = rec(root->left);
        int r = rec(root->right);
        m = max(m, l + r);
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return m;
    }
};

