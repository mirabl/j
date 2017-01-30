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
    void aux(TreeNode *root, int sum, vector<int>& pref, int *count) {
        if (!root) {
            return;
        }
        pref.push_back(0);
        for (int i = 0; i < int(pref.size()); i++) {
            pref[i] += root->val;
        }
        for (int x: pref) {
            if (x == sum) {
                (*count)++;
            }
        }
        aux(root->left, sum, pref, count);
        aux(root->right, sum, pref, count);
        pref.pop_back();
        for (int i = 0; i < int(pref.size()); i++) {
            pref[i] -= root->val;
        }
    }

    int pathSum(TreeNode* root, int sum) {
        vector<int> pref;
        int count = 0;
        aux(root, sum, pref, &count);
        return count;
    }
};