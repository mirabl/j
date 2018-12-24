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
    void dfs(TreeNode* root, int depth, int* m) {
        if (!root->left && !root->right) {
            if (*m == -1 || depth + 1 < *m) {
                *m = depth + 1;
            }
        } else {
            if (root->left) {
                dfs(root->left, depth + 1, m);
            }
            if (root->right) {
                dfs(root->right, depth + 1, m);
            }
        }
    }

    int minDepth(TreeNode* root) {
        int m = -1;
        if (!root) {
            return 0;
        }
        dfs(root, 0, &m);
        return m;
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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int m = -1;
        if (root->left) {
            m = 1 + minDepth(root->left);
        }
        if (root->right) {
            int r = 1 + minDepth(root->right);
            if (m == -1 || r < m) {
                m = r;
            }
        }
        return m;
    }
};

