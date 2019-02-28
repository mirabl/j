/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root, int d) {
        if (!root) {
            return 0;
        }
        return max(d + 1, max(maxDepth(root->left, d + 1), maxDepth(root->right, d + 1)));
    }
    
    Node *prev;
    
    void trav(Node* root, int cur, int target) {
        if (!root) {
            return;
        }
        if (cur == target) {
            if (prev) {
                prev->next = root;
            }
            prev = root;
        } else {
            trav(root->left, cur + 1, target);
            trav(root->right, cur + 1, target);
        }
    }
    
    Node* connect(Node* root) {
        int d = maxDepth(root, 0);
        
        for (int i = 1; i <= d; i++) {
            prev = NULL;
            trav(root, 0, i);
        }
        
        return root;
    }
};
