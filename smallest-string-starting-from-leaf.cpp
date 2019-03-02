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
    string smallestFromLeaf(TreeNode* root) {
        if (!root) {
            return "{";
        }
        
        if (!root->left && !root->right) {
            return string(1, 'a' + root->val);
        }
        
        string l = smallestFromLeaf(root->left);
        string r = smallestFromLeaf(root->right);
        
       // cout << "l=" << l << ", r=" << r << ", smallest=" << (l < r ? l : r) << endl;
        
        string res = (l < r ? l : r) + char('a' + root->val);
        return res;
    }
};
