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
    vector<TreeNode*> ino;
    
    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        ino.push_back(root);
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        
        inorder(root);
        for (int i = 0; i < int(ino.size()); i++) {
            ino[i]->left = NULL;
            ino[i]->right = i + 1 < int(ino.size()) ? ino[i + 1] : NULL;
        }
        
        return ino[0];
    }
};
