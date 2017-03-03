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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> curS;
        stack<TreeNode*> nextS;
        curS.push(root);
        while (!curS.empty()) {
            vector<int> row;
            while (!curS.empty()) {
                TreeNode *x = curS.top();
                curS.pop();
                if (x) {
                    row.push_back(x->val);
                    nextS.push(res.size() % 2 == 0 ? x->left : x->right);
                    nextS.push(res.size() % 2 == 0 ? x->right : x->left);
                }
            }
            swap(curS, nextS);
            if (!row.empty()) {
                res.push_back(row);
            }
        }
        return res;
    }
};