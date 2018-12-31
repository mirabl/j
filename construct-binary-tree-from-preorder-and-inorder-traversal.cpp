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
    TreeNode* rr(vector<int>& preorder, int plo, int phi, vector<int>& inorder, int ilo, int ihi) {
        if (phi < plo) {
            return NULL;
        }
        int v = preorder[plo];
        TreeNode *root = new TreeNode(v);
        int j;
        for (j = ilo; inorder[j] != v; j++) 
            ;
        int numLeft = j - ilo;
        int numRight = phi - plo - numLeft;
        root->left = rr(preorder, plo + 1, plo + numLeft, inorder, ilo, j - 1);
        root->right = rr(preorder, plo + numLeft + 1, phi, inorder, j + 1, ihi);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = int(preorder.size()) - 1;
        return rr(preorder, 0, n, inorder, 0, n);
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
    TreeNode* rec(vector<int>& preorder, vector<int>& inorder, int plo, int phi, int ilo, int ihi) {
        if (plo > phi) {
            return NULL;
        }
        int v = preorder[plo];
        TreeNode *r = new TreeNode(v);        
        
        int sizeLeft = 0;
        while (inorder[ilo + sizeLeft] != v) {
            sizeLeft++;
        } 
        
        int ploLeft = plo + 1;
        int phiLeft = ploLeft + sizeLeft - 1;
        int iloLeft = ilo;
        int ihiLeft = ilo + sizeLeft - 1;
        
        r->left = rec(preorder, inorder, ploLeft, phiLeft, iloLeft, ihiLeft);
        
        int ploRight = phiLeft + 1;
        int phiRight = phi;
        int iloRight = ihiLeft + 2;
        int ihiRight = ihi;
        
        r->right = rec(preorder, inorder, ploRight, phiRight, iloRight, ihiRight);
        return r;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return rec(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    
};

