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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) {
            return 0;
        }
        
        int res = root->val >= L && root->val <= R ? root->val : 0;
        return res + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};
// does not use BST property

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) {
            return 0;
        }
        
        int s = 0;
        if (R > root->val) {
            s += rangeSumBST(root->right, L, R);
        }
        if (L < root->val) {
            s += rangeSumBST(root->left, L, R);
        }
        if (root->val >= L && root->val <= R) {
            s += root->val;
        }
        return s;
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
    int s = 0;
    
    void r(TreeNode* root, int L, int R) {
        if (!root) {
            return;
        }
        if (root->val >= L && root->val <= R) {
            s += root->val;
        }
        r(root->left, L, R);
        r(root->right, L, R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        r(root, L, R);
        return s;
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        queue<TreeNode*> Q;
        Q.push(root);
        
        int res = 0;
        while (!Q.empty()) {
            TreeNode *p = Q.front();
            Q.pop();
            if (!p) {
                continue;
            }
            
            if (p->val >= L && p->val <= R) {
                res += p->val;
            }
            Q.push(p->left);
            Q.push(p->right);
        }
        
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        queue<TreeNode*> Q;
        Q.push(root);
        
        int res = 0;
        while (!Q.empty()) {
            TreeNode *p = Q.front();
            Q.pop();
            if (!p) {
                continue;
            }
            
            if (p->val >= L && p->val <= R) {
                res += p->val;
            }
            if (p->val >= L) Q.push(p->left);
            if (p->val <= R) Q.push(p->right);
        }
        
        return res;
    }
};
