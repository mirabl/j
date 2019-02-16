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
    bool tr(TreeNode *root, vector<int>& voyage, int lo, int hi, vector<int>& ans) {
     //   cout << "tr root->val=" << root->val << ", lo=" << lo << ", hi=" << hi << endl;
         
        if (root->val != voyage[lo]) {
        //    cout << "root->val not match " << root->val << " " << voyage[lo] << endl;
            return false;
        }
        
        if (!root->right && !root->left) {
            // cout << "no child: " << ((lo >= hi) ? "true " : " false") << endl;
            return lo >= hi;
        } else if (!root->right) {
            return tr(root->left, voyage, lo + 1, hi, ans);
        } else if (!root->left) {
            return tr(root->right, voyage, lo + 1, hi, ans);
        } else {
            if (lo > hi) {
                return false;
            }
            if (voyage[lo + 1] == root->left->val) {
                int mid = lo + 1;
                while (voyage[mid] != root->right->val) {
                    mid++;
                }
                return tr(root->left, voyage, lo + 1, mid - 1, ans) && tr(root->right, voyage, mid, hi, ans);
            } else if (voyage[lo + 1] == root->right->val) {
                int mid = lo + 1;
                while (voyage[mid] != root->left->val) {
                    mid++;
                }
                ans.push_back(root->val);
                if (tr(root->right, voyage, lo + 1, mid - 1, ans) && tr(root->left, voyage, mid, hi, ans)) {
                    return true;
                } else {
                    ans.pop_back();
                }
            } else {
                return false;
            }
        }
        return false;
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (!root) {
            return {};
        }
        int n = int(voyage.size()) - 1;
        vector<int> ans;
        return tr(root, voyage, 0, n, ans) ? ans : vector<int>{-1};
        
    }
};
