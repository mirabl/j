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
        o.push_back(root->val);
        for (auto c: root->children) {
            r(c, o);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        r(root, res);
        return res;
    }
};
