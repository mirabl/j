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
    int res;
    
    int maxPathDown(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = maxPathDown(root->left);
        int r = maxPathDown(root->right);
        res = max(res, l + r);
        
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        maxPathDown(root);
        return res;
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
    int b = 0;
    
    int pathLenDown(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = pathLenDown(root->left);
        int r = pathLenDown(root->right);
        
        b = max(l + r, b);
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pathLenDown(root);
        return b;
    }
};
