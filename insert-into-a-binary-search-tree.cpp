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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            if (!root->left) {
                root->left = new TreeNode(val);
            } else {
                insertIntoBST(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new TreeNode(val);
            } else {
                insertIntoBST(root->right, val);
            }
        }
        
        return root;
    }
};

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* p = new TreeNode(val);
        if (!root) {
            return p;
        }
        if (val < root->val) {
            if (!root->left) {
                root->left = p;
            } else {
                insertIntoBST(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = p;
            } else {
                insertIntoBST(root->right, val);
            }
        }
        return root;
    }
};
