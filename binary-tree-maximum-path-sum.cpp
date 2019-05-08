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
    pair<int, int> getBest(TreeNode *root) {
        if (!root) {
            return {-1e8, -1e8};
        }
        int bComplete, bIncomplete;
        
        auto pLeft = getBest(root->left);
        auto pRight = getBest(root->right);
        
        bComplete = max(max(pLeft.first, pRight.first), root->val + max(pLeft.second, 0) + max(pRight.second, 0));
        bIncomplete = root->val + max(max(pLeft.second, pRight.second), 0);
        
        return {bComplete, bIncomplete};
    }
    
    int maxPathSum(TreeNode* root) {
        auto p = getBest(root);
        return max(p.first, p.second);
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
    int infty = 1e9;
    pair<int, int> r(TreeNode *root) {
        if (!root) {
            return {- infty, -infty};
        }
        auto pr = r(root->right);
        auto pl = r(root->left);
        
        int incomplete = root->val + max(max(pr.first, pl.first), 0);
        int complete = max(max(pr.second, pl.second), root->val + max(pr.first, 0) + max(pl.first, 0));
        return {incomplete, complete};
    }
    
    int maxPathSum(TreeNode* root) {
        auto p = r(root);
        return max(p.first, p.second);
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
    int best = -1e8;
    
    int r(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int mr = max(r(root->right), 0);
        int ml = max(r(root->left), 0);
        
        best = max(best, root->val + ml + mr);
        return root->val + max(mr, ml);
    }
    
    int maxPathSum(TreeNode* root) {
        r(root);
        return best;
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
    int best = -1e8;
    
    int rec(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = rec(root->left);
        int r = rec(root->right);
        best = max(best, root->val + r + l);
        return max(root->val + max(l, r), 0);
    }
    
    int maxPathSum(TreeNode* root) {
        rec(root);
        return best;
    }
};
