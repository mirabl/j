/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        
        vector<vector<int>> res;
        queue<Node*> Q;
        Q.push(root);
        
        while (!Q.empty()) {
            vector<int> level;
            
            for (int n = Q.size(); n > 0; n--) {
                Node* node = Q.front();
                Q.pop();

                level.push_back(node->val);
                
                for (auto child: node->children) {
                   Q.push(child);   
                }
            }
            res.push_back(level);
        }
        
        return res;
    }
};
