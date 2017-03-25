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
    void rec(TreeNode* root, int *acc) {
        if (root) {
            rec(root->right, acc);
            int tmp = *acc + root->val;
            root->val += *acc;
            *acc = tmp;
            rec(root->left, acc);
        }
    }

    TreeNode* convertBST(TreeNode* root) {
        int acc = 0;
        rec(root, &acc);
        return root;
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
    void rec(TreeNode* root, int *acc) {
        if (root) {
            rec(root->right, acc);
            root->val += *acc;
            *acc = root->val;
            rec(root->left, acc);
        }
    }

    TreeNode* convertBST(TreeNode* root) {
        int acc = 0;
        rec(root, &acc);
        return root;
    }
};

