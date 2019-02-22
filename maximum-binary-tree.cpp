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
    TreeNode* f(vector<int>& nums, int lo, int hi) {
        if (lo > hi) {
            return NULL;
        }
        int iMax = lo;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] > nums[iMax]) {
                iMax = i;
            }
        }
        auto n = new TreeNode(nums[iMax]);
        n->left = f(nums, lo, iMax - 1);
        n->right = f(nums, iMax + 1, hi);
        return n;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return f(nums, 0, n - 1);
    }
};
