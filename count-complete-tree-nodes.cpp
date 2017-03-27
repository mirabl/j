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
    void rec(TreeNode *root, int *count) {
        if (root) {
            (*count)++;
            rec(root->left, count);
            rec(root->right, count);
        }
    }

    int countNodesTLE(TreeNode* root) {
        int c = 0;
        rec(root, &c);
        return c;
    }

    TreeNode* descent(TreeNode *root, int path, int h) {
        for (int i = 0; i < h - 1; i++) {
            int bit = (path >> (h - 2 - i)) & 1;
            root = bit ? root->right : root->left;
        }
        return root;
    }
    
    int BS(TreeNode *root, int h) {
        int m = (1 << (h - 1)) - 1;
        int lo = 0;
        int hi = m;
        while (true) {
            int mid = lo + (hi - lo) / 2;
            if (!descent(root, mid, h)) {
                hi = mid - 1;
            } else if (mid == m || !descent(root, mid + 1, h)) {
                return mid;
            } else {
                lo = mid + 1;
            }
        }
        return -1; // Not reached.
    }
    
    int countNodes(TreeNode* root) {
        if (!root) { 
            return 0;
        }
        
        int h = 0;
        TreeNode *p = root;
        while (p) {
            h++;
            p = p->left;
        }
        
        int v = BS(root,  h);
        return (1 << (h - 1)) + v;
    }

    
};


// simpler: https://discuss.leetcode.com/topic/15533/concise-java-solutions-o-log-n-2

