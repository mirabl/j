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
    int dfs(TreeNode *root, int partial) {
        if (!root) {
            return 0;
        }
        int v = (partial * 10) + root->val;
        if (!root->left && !root->right) {
            return v;
        } else {
            return dfs(root->left, v) + dfs(root->right, v);
        }
    }


    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};