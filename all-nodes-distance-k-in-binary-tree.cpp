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
    map<int, vector<int>> G;
    set<int> visited;
    
    void buildGraph(TreeNode* root) {
        if (!root || visited.count(root->val) == 1) {
            return;
        }
        visited.insert(root->val);
        for (auto child: vector<TreeNode*>{root->right, root->left}) {
           if (child) {
                G[child->val].push_back(root->val);
                G[root->val].push_back(child->val);
                buildGraph(child);
            }
        }
    }
    
    void dfs(int root, int d, vector<int>& res) {
        if (visited.count(root) == 1) {
            return;
        }
        visited.insert(root);
        if (d == 0) {
            res.push_back(root);
        } else {
            for (auto v: G[root]) {
                dfs(v, d - 1, res);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(root);
        visited.clear();
        vector<int> res;
        dfs(target->val, K, res);
        
        return res;
    }
};
