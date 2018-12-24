/*
https://leetcode.com/problems/house-robber-iii/
*/
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
    map<pair<TreeNode*, bool>, int> memo;
    int rob_rec(TreeNode *root, bool rob) {
        if (memo.count(pair<TreeNode*, bool>(root, rob)) == 1) {
            return memo[pair<TreeNode*, bool>(root, rob)];
        }
        if (root == NULL) {
            return 0;
        }
        int thisone = 0;
        if (rob) {
            thisone = root->val + rob_rec(root->left, false) + rob_rec(root->right, false);
        }
        memo[pair<TreeNode*, bool>(root, rob)] = max(thisone, rob_rec(root->left, true) + rob_rec(root->right, true));
        return memo[pair<TreeNode*, bool>(root, rob)];
    }

    int rob(TreeNode* root) {
        return rob_rec(root, true);
    }
};