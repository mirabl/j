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
    int moves;
    
    int f(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int bl = f(root->left);
        int br = f(root->right);
        moves += abs(bl) + abs(br);
        return root->val + bl + br - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        moves = 0;
        f(root);
        return moves;
    }
};
