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
    int n;
    
    TreeNode* r(vector<int>& pre, int lo, int hi) {
        if (lo > hi) {
            return NULL;
        }
        auto root = new TreeNode(pre[lo]);
        int rr = lo + 1;
        while (rr <= hi && pre[rr] < pre[lo]) {
            rr++;
        }
        root->left = r(pre, lo + 1, rr - 1);
        root->right = r(pre, rr, hi);
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = int(preorder.size()) - 1;
        return r(preorder, 0, n);
    }
};
