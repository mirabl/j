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
    void rec(TreeNode *root, int T, vector<int>& pref, vector<vector<int>>& res) {
        if (!root) {
            return;
        }
        pref.push_back(root->val);
        if (!root->left && !root->right) {
            if (T == root->val) {
                res.push_back(pref);
            }
        } else {
            rec(root->left, T - root->val, pref, res);
            rec(root->right, T - root->val, pref, res);
        }
        pref.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> pref;
        rec(root, sum, pref, res);
        return res;
    }
};