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
    vector<int> toArray(TreeNode *root) {
        if (!root) {
            return {};
        }
        auto vL = toArray(root->left);
        vector<int> res;
        for (int x: vL) {
            res.push_back(x);
        }
        res.push_back(root->val);
        for (int x: toArray(root->right)) {
            res.push_back(x);
        }
        return res;
    }
    
    TreeNode* toTree(vector<int>& V, int lo, int hi) {
        if (lo > hi) {
            return NULL;
        }
        int iMax = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (V[i] > V[iMax]) {
                iMax = i;
            }
        }
        TreeNode *root = new TreeNode(V[iMax]);
        root->left = toTree(V, lo, iMax - 1);
        root->right = toTree(V, iMax + 1, hi);
        return root;
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> V = toArray(root);
        V.push_back(val);
        return toTree(V, 0, int(V.size()) - 1);
    }
};
