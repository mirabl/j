/*
// Definition for a Node.
class Node {
public:
    int val;
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
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        
        unordered_set<Node*> visited;
        queue<pair<Node*, int>> Q;
        Q.push({root, 1});
        int d = 0;
        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            for (auto c: (p.first)->children) {
                Q.push({c, p.second + 1});
            }
            d = p.second;
        }
        return d;
    }
};
