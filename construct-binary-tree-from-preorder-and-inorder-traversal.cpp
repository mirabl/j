class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return NULL;
        }
        
        int root = preorder[0];
        int k;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root) {
                k = i;
                break;
            }
        }
        
        vector<int> leftInorder(inorder.begin(), inorder.begin() + k);
        vector<int> rightInorder(inorder.begin() + k + 1, inorder.end());
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + k + 1);
        vector<int> rightPreorder(preorder.begin() + k + 1, preorder.end());
        
        TreeNode *nroot = new TreeNode(root);
        nroot->left = buildTree(leftPreorder, leftI = buildTree(rightPreorder, rightInorder);
        return nroot;
    }
};

//

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pS, int pE, int iS, int iE) {
        if (pE < pS) {
            return NULL;
        }
        
        int root = preorder[pS];
        int k;
        for (int i = iS; i <= iE; i++) {
            if (inorder[i] == root) {
                k = i;
                break;
            }
        }
        k -= iS;
        
        TreeNode *nroot = new TreeNode(root);
        nroot->left = buildTree(preorder, inorder, pS + 1, pS + k, iS, iS + k - 1);
        nroot->right = buildTree(preorder, inorder, pS + k + 1, pE, iS + k + 1, iE);
        return nroot;
    }

