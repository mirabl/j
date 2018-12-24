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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        } else if (q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
        
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v = root->val;
        if (p->val == v || q->val == v) {
            return root;
        }
        if (p->val > q->val) {
            swap(p, q);
        }
        if (p->val < v) {
            return q->val > v ? root : lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};