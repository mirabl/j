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
    void dfs(TreeNode *root, int level, map<int, vector<int>>& M) {
        if (!root) {
            return;
        }
        M[level].push_back(root->val);
        dfs(root->left, level + 1, M);
        dfs(root->right, level + 1, M);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        map<int, vector<int>> M;
        dfs(root, 0, M);
        vector<vector<int>> V;
        for (int i = 0; M.count(i) != 0; i++) {
            V.push_back(M[i]);
        }
        reverse(V.begin(), V.end());
        return V;
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        res.push_back(vector<int>());
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);
        while (!Q.empty()) {
            TreeNode *n = Q.front();
            Q.pop();
            if (n == NULL) {
                if (Q.empty()) {
                    break;
                }
                Q.push(NULL);
                res.push_back(vector<int>());
            } else {
                res.back().push_back(n->val);
                if (n->left) {
                    Q.push(n->left);
                }
                if (n->right) {
                    Q.push(n->right);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;        
    }
};