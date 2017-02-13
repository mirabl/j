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
    int max_level = -1;
    int max_value = 0;
    void dfs(TreeNode *root, int level) {
        if (root) {
            if (level > max_level) {
                max_level = level;
                max_value = root->val;
            }
            dfs(root->left, level + 1);
            dfs(root->right, level + 1);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return max_value;
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int res;
        while (!Q.empty()) {
            int n = Q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *p = Q.front();
                Q.pop();
                if (p) {
                    Q.push(p->right);
                    Q.push(p->left);
                    res = p->val;
                }
            }
        }
        return res;
    }
};

