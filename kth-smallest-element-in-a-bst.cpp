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
    bool rec(TreeNode* root, int *pk, int *pres) {
        if (!root) {
            return false;
        } else if (rec(root->left, pk, pres)) {
            return true;
        } else if (*pk == 1) {
            *pres = root->val;
            return true;
        } else {
            (*pk)--;
            return rec(root->right, pk, pres);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int res;
        rec(root, &k, &res);
        return res;
    }
};