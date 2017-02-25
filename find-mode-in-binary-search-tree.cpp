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
    void rec(TreeNode *root, map<int, int>& M) {
        if (!root) {
            return;
        }
        M[root->val]++;
        rec(root->left, M);
        rec(root->right, M);
    }

    vector<int> findMode(TreeNode* root) {
        map<int, int> M;
        rec(root, M);
        vector<int> res;
        int max = 0;
        for (auto p: M) {
            if (p.second >= max) {
                if (res.empty() || p.second > max) {
                    res.clear();
                    max = p.second;
                }
                res.push_back(p.first);
            } 
        }
        return res;
    }
};