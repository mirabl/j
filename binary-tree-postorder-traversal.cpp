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
    typedef enum { 
        PRINT, 
        DO
    } Action;
    
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, Action>> S;
        vector<int> res;
        S.push({root, DO});
        
        while (!S.empty()) {
            auto p = S.top();
            S.pop();
            auto node = p.first;
            auto action = p.second;
            
            if (!node) {
                continue;
            }
            
            if (action == DO) {
                S.push({node, PRINT});
                S.push({node->right, DO});
                S.push({node->left, DO});
            } else {
                res.push_back(node->val);
            }
        }
        
        return res;
    }
};

