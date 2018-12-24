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
    void rec(TreeNode* root, vector<string>& res, vector<int>& prefix) {
        if (!root) {
            return;
        }
        prefix.push_back(root->val);
        if (!root->left && !root->right) {
            string s = to_string(prefix[0]);
            for (int i = 1; i < int(prefix.size()); i++) {
                s = s + "->" + to_string(prefix[i]);
            }
            res.push_back(s);
        } else {
            rec(root->left, res, prefix);
            rec(root->right, res, prefix);
        }
        prefix.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> prefix;
        rec(root, res, prefix);
        return res;
    }
};