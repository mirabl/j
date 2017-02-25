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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int n = Q.size();
            int m = Q.front()->val;
            while (n > 0) {
                TreeNode *x = Q.front();
                Q.pop();
                m = max(m, x->val);
                if (x->left) {
                    Q.push(x->left);
                }
                if (x->right) {
                    Q.push(x->right);
                }
                n--;
            }
            res.push_back(m);
        }
        return res;
    }
};