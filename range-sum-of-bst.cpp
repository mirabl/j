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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) {
            return 0;
        }
        
        int res = root->val >= L && root->val <= R ? root->val : 0;
        return res + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};
// does not use BST property
