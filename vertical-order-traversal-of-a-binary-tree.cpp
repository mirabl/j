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
    map<int, vector<pair<int, int>>> byX;
    
    void rec(TreeNode *root, int x, int y) {
        if (!root) {
            return;
        }
        
        byX[x].push_back({- y, root->val});
        rec(root->left, x - 1, y - 1);
        rec(root->right, x + 1, y - 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        rec(root, 0, 0);
        
        for (int x = -10000; x < 10000; x++) {
            if (byX[x].size() == 0) {
                continue;
            }
            
            auto l = byX[x];
            sort(l.begin(), l.end());
            vector<int> ll;
            for (auto p: l) {
                ll.push_back(p.second);
            }
            res.push_back(ll);
            
        }
        return res;
    }
};

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
    map<int, vector<pair<int, int>>> byX;
    
    void rec(TreeNode *root, int x, int y) {
        if (!root) {
            return;
        }
        
        byX[x].push_back({ y, root->val });
        rec(root->left, x - 1, y + 1);
        rec(root->right, x + 1, y + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        rec(root, 0, 0);
        
        for (auto kvp: byX) {
            auto l = kvp.second;
            if (l.empty()) {
                continue;
            }
            sort(l.begin(), l.end());
            vector<int> ll;
            for (auto p: l) {
                ll.push_back(p.second);
            }
            res.push_back(ll);
            
        }
        return res;
    }
};
