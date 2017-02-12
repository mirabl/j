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
    map<int, int> F;
    
    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int v = root->val + dfs(root->left) + dfs(root->right);
        F[v]++;
        return v;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int m = -1;
        for (auto x: F) {
            m = max(m, x.second);
        }
        vector<int> V;
        for (auto x: F) {
            if (x.second == m) {
                V.push_back(x.first);
            }
        }
        return V;
    }
};