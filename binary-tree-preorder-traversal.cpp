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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode* n = S.top();
            S.pop();
            if (n) {
                res.push_back(n->val);
                S.push(n->right);
                S.push(n->left);
            }
        }
        return res;
    }
};