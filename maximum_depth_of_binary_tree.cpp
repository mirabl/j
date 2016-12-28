/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
104. Maximum Depth of Binary Tree   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 201377
Total Submissions: 397533
Difficulty: Easy
Contributors: Admin
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
alias a='g++ -Wall -std=c++11 -g maximum_depth_of_binary_tree.cpp && ./a.out'
*/
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) { }
};

int maxDepth(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
	TreeNode n0(0);
	cout << maxDepth(&n0) << " 1" << endl;

	TreeNode n1(1);
	n0.left = &n1;
	cout << maxDepth(&n0) << " 2" << endl;

	n0.left = NULL;
	n0.right = &n1;
	cout << maxDepth(&n0) << " 2" << endl;

	TreeNode n2(2);
	n0.left = &n1;
	n0.right = &n2;
	cout << maxDepth(&n0) << " 2" << endl;

	n0.right = NULL;
	n1.left = &n2;
	cout << maxDepth(&n0) << " 3" << endl;

	TreeNode n3(3);
	n0.right = &n3;
	cout << maxDepth(&n0) << " 3" << endl;
}