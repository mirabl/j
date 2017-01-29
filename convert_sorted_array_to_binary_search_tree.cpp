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
    TreeNode * rec(vector<int>& nums, int lo, int hi) {
        if (lo > hi) { 
            return NULL;
        }
        int mid = lo + (hi - lo) / 2;
        TreeNode *n = new TreeNode(nums[mid]);
        n->left = rec(nums, lo, mid - 1);
        n->right = rec(nums, mid + 1, hi);
        return n;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rec(nums, 0, int(nums.size()) - 1);
    }
};