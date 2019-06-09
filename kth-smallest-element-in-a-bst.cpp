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
    int c = 0;
    int res;
    
    void r(TreeNode *root, int k) {
        if (!root) {
            return;
        }
        
        r(root->left, k);
        c++;
        if (k == c) {
            res = root->val;
        } else if (k > c) {
            r(root->right, k);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        r(root, k);
        return res;
    }
};
