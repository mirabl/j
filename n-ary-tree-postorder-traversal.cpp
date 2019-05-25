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
    void r(Node* root, vector<int>& o) {
        if (!root) {
            return;
        }
        for (auto c: root->children) {
            r(c, o);
        }
        o.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> res;
        r(root, res);
        return res;
    }
};
