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
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> r;
        if (root == NULL) {
            return r;
        }
        vector<int> r1 = inorderTraversal(root->left);
        r.insert(r.end(), r1.begin(), r1.end());
        r.push_back(root->val);
        r1 = inorderTraversal(root->right);
        r.insert(r.end(), r1.begin(), r1.end());
        return r;        
    }
    
    void inorderTraversalRec(TreeNode* root, vector<int>& r) {
        if (root == NULL) {
            return;
        }
        inorderTraversalRec(root->left, r);
        r.push_back(root->val);
        inorderTraversalRec(root->right, r);
    }
    
    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> r;
        inorderTraversalRec(root, r);
        return r;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> V;
        TreeNode *cur = root;
        while (cur != NULL || !S.empty()) {
            if (cur != NULL) {
                S.push(cur);
                cur = cur->left;
            } else {
                cur = S.top();
                S.pop();
                V.push_back(cur->val);
                cur = cur->right;
            }
        }
        return V;
    }
    
};