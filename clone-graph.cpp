/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    map<int, Node*> M;
    
public:
    Node* cloneGraph(Node* node) {
        if (M.count(node->val) == 0) {
            auto n = new Node(node->val);
            M[node->val] = n;
            for (auto neigh: node->neighbors) {
                n->neighbors.push_back(cloneGraph(neigh));
            }
        }
        return M[node->val];
    }
    
};
