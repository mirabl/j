// contest
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
    vector<int> values;
    
    void getValues(TreeNode* root) {
        if (root) {
            values.push_back(root->val);
        getValues(root->right);
        getValues(root->left);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        getValues(root);
        
        
        int m = 0;
        for (int i = 0; i < values.size(); i++) {
            for (int j = i + 1; j < values.size(); j++) {
                if (m == 0 || abs(values[i] - values[j]) < m) {
                    m = abs(values[i] - values[j]);
                }
            }
        }
        return m;
    }
};

