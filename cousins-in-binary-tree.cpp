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
    pair<int, int> notFound = { -1, -1};
    
    pair<int, int> rr(TreeNode *root, int x, int d, TreeNode *parent) {
        if (!root) {
            return notFound;
        }
        if (root->val == x && parent) {
            return {d, parent->val};
        }
        auto l = rr(root->left, x, d + 1, root);
        auto r = rr(root->right, x, d + 1, root);
        if (l != notFound) {
            return l;
        }
        return r;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        auto p = rr(root, x, 0, NULL);
        auto q = rr(root, y, 0, NULL);
        
        return p.first == q.first && p.second != q.second;
    }
};
