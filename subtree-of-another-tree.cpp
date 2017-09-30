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
    bool equals(TreeNode* s, TreeNode* t) {
        if (!s || !t) {
            return s == t;
        } else {
            return s->val == t->val && equals(s->left, t->left) && equals(s->right, t->right);
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (equals(s, t)) {
            return true;
        }
        return s && (isSubtree(s->right, t) || isSubtree(s->left, t));
    }
};

// https://discuss.leetcode.com/topic/88491/java-concise-o-n-m-time-o-n-m-space
// preorder string

// https://discuss.leetcode.com/topic/88520/python-straightforward-with-explanation-o-st-and-o-s-t-approaches/2
// hash subtree merkle