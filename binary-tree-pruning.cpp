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
    int sumSubtree(TreeNode *root) {
        if (!root) {
            return 0;
        } else {
            return root->val + sumSubtree(root->left) + sumSubtree(root->right);
        }
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        if (sumSubtree(root->left) == 0) {
            root->left = NULL;
        } else {
            pruneTree(root->left);
        }
        if (sumSubtree(root->right) == 0) {
            root->right = NULL;
        } else {
            pruneTree(root->right);
        }
        
        if (!root->right && !root->left && root->val == 0) {
            return NULL;
        }
        
        return root;
    }
};
