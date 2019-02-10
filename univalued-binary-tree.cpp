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
    bool r(TreeNode* root, int last) {
        if (!root) {
            return true;
        }
        
        if (last != -1 && root->val != last) {
            return false;
        }
        
        return r(root->left, root->val) && r(root->right, root->val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        return r(root, -1);
    }
};
