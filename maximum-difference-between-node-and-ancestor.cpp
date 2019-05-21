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
    int infty = 1e8;
    int best = - infty;
    
    void rec(TreeNode *root, int m, int M) {
        if (!root) {
            return;
        }
        best = max(best, abs(root->val - m));
        best = max(best, abs(root->val - M));
        m = min(m, root->val);
        M = max(M, root->val);
        rec(root->left, m, M);
        rec(root->right, m, M);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        rec(root->left, root->val, root->val);
        rec(root->right, root->val, root->val);
        return best;
    }
};
