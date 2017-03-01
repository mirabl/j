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

    void rec(TreeNode *root, int *prev, int *res) {
        if (root->left) {
            rec(root->left, prev, res);
        }
        if (*prev != -1) {
            int x = root->val - *prev;
            if (*res == -1 || x < *res) {
                *res = x;
            }
        }
        *prev = root->val;
        if (root->right) {
            rec(root->right, prev, res);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int res = -1;
        rec(root, &prev, &res);
        return res;
    }


    // BAD
    int tmax(TreeNode *root) {
        return root->right ? tmax(root->right) : root->val;
    }
    
    int tmin(TreeNode *root) {
        return root->left ? tmin(root->left) : root->val;
    }

    int getMinimumDifference2(TreeNode* root) {
        int res = -1;
        if (root->left) {
            int m = tmax(root->left);
            res = root->val - m;
        }
        if (root->right) {
            int M = tmin(root->right);
            if (res == -1 || M - root->val < res) {
                res = M - root->val;
            }
        }
        for (TreeNode *p: {root->left, root->right}) {
            if (p) {
                int x = getMinimumDifference(p);
                if (x != -1) {
                    res = min(res, x);
                }
            }
        }
        return res;
    }
};