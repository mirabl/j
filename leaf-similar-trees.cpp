// https://leetcode.com/contest/weekly-contest-94/problems/leaf-similar-trees/
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
    void leaves(TreeNode* root, vector<int>& l) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            l.push_back(root->val);
        } else {
            leaves(root->left, l);
            leaves(root->right, l);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        
        leaves(root1, l1);
        leaves(root2, l2);
        
        return l1 == l2;
    }
};