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
    int rec(TreeNode* root, int *pacc) {
        if (!root) {
            return 0;
        }
        int l = rec(root->left, pacc);
        int r = rec(root->right, pacc);
        *pacc += abs(l - r);
        return l + r + root->val;
    }

    int findTilt(TreeNode* root) {
        int acc = 0;
        rec(root, &acc);
        return acc;
    }
};