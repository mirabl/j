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

