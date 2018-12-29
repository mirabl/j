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
    set<int> pos;
    
    void r(TreeNode* root, int v) {
        if (!root) {
            return;
        }
        
        pos.insert(v);
        r(root->left, 2 * v);
        r(root->right, 2 * v + 1);
    }
    
    bool isCompleteTree(TreeNode* root) {
        r(root, 1);
        
        int n = pos.size();
        for (int i = 1; i <= n; i++) {
            if (pos.count(i) == 0) {
                return false;
            }
        }
        return true;
    }
};
