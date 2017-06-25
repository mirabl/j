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
    TreeNode* rec(TreeNode *root, int v, int d) {
        if (root) {
            if (d > 2) {
                rec(root->left, v, d - 1);
                rec(root->right, v, d - 1);
            } else if (d == 1) {
                TreeNode *l = new TreeNode(v);
                l->left = root;
                swap(l, root);
            } else if (d == 2) {
                TreeNode *l = new TreeNode(v);
                l->left = root->left;
                root->left = l;
                TreeNode *r = new TreeNode(v);
                r->right = root->right;
                root->right = r;
            }
        }
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return rec(root, v, d);
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *n = new TreeNode(v);
            n->left = root;
            return n;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int n = Q.size();
            while (n > 0) {
                TreeNode *x = Q.front();
                Q.pop();
                if (d == 2) {
                    TreeNode *l = new TreeNode(v);
                    l->left = x->left;
                    x->left = l;
                    TreeNode *r = new TreeNode(v);
                    r->right = x->right;
                    x->right = r;
                } else {
                    if (x->left) {
                        Q.push(x->left);
                    }
                    if (x->right) {
                        Q.push(x->right);
                    }
                }
                n--;
            }
            d--;
        }
        return root;
    }
};

