/*
https://leetcode.com/problems/validate-binary-search-tree/
98. Validate Binary Search Tree   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 131513
Total Submissions: 590987
Difficulty: Medium
Contributors: Admin
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
alias a='g++ -Wall -std=c++11 validate_binary_search_tree.cpp && ./a.out'
*/
#include <iostream>
#include <climits>

using namespace std;

struct  TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) { }
};

bool isValidBSTRec(TreeNode *root, TreeNode *node_min, TreeNode *node_max) {
	if (root == NULL) {
		return true;
	}
	return ((node_min == NULL || root->val > node_min->val)
	        && (node_max == NULL || root->val < node_max->val)
			&& (root->left == NULL || isValidBSTRec(root->left, node_min, root))
			&& ((root->right == NULL) || isValidBSTRec(root->right, root, node_max)));
}

bool isValidBST(TreeNode *root) {                                     
	return isValidBSTRec(root, NULL, NULL);
}

int main() {
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);

	n2.left = &n1;
	n2.right = &n3;
	cout << isValidBST(&n2) << " 1" << endl;

	n2.left = NULL;
	n2.right = NULL;
	n1.left = &n2;
	n1.right = &n3;
	cout << isValidBST(&n1) << " 0" << endl;

}