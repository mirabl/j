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
    bool equals(TreeNode *a, TreeNode *b) {
        return a && b && a->val == b->val;
    }
    
    int longestUnivaluePathValue(TreeNode* root) {
           return max(equals(root, root->left) ? 1 + longestUnivaluePathValue(root->left) : 0,
                      equals(root, root->right) ? 1 + longestUnivaluePathValue(root->right) : 0);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        vector<int> res;
        int with_value = 0;
        if (equals(root, root->left)) {
            with_value += 1 + longestUnivaluePathValue(root->left);
        }
        if (equals(root, root->right)) {
            with_value += 1 + longestUnivaluePathValue(root->right);
        }
        res.push_back(with_value);
        res.push_back(longestUnivaluePath(root->left));
        res.push_back(longestUnivaluePath(root->right));
        return *max_element(res.begin(), res.end());
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
    bool equals(TreeNode *a, TreeNode *b) {
        return a && b && a->val == b->val;
    }
    
    int longestUnivaluePathValue(TreeNode* root) {
           return max(equals(root, root->left) ? 1 + longestUnivaluePathValue(root->left) : 0,
                      equals(root, root->right) ? 1 + longestUnivaluePathValue(root->right) : 0);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int with_value = equals(root, root->left) ? 1 + longestUnivaluePathValue(root->left) : 0;
        with_value += equals(root, root->right) ? 1 + longestUnivaluePathValue(root->right) : 0;
        return max(with_value, max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
    }
};

