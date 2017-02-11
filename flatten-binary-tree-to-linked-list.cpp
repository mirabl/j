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
    TreeNode* dfs(TreeNode *root, TreeNode *prev) {
        if (!root) {
            return prev;
        }
        if (prev) {
            prev->right = root;
        }
        TreeNode *tmp = root->right;
        prev = dfs(root->left, root);
        root->left = NULL;
        return dfs(tmp, prev);
    }

    void flatten(TreeNode* root) {
        dfs(root, NULL);        
    }
};