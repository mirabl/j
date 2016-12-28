/*
https://leetcode.com/problems/balanced-binary-tree/
110. Balanced Binary Tree   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 147782
Total Submissions: 409326
Difficulty: Easy
Contributors: Admin
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
alias a='g++ -Wall -std=c++11 -g balanced_binary_tree.cpp && ./a.out'
*/
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) { }
};

int isBalancedWithHeight(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int num_left = isBalancedWithHeight(root->left);
	int num_right = isBalancedWithHeight(root->right);
	if (num_left == -1 || num_right == -1) {
		return -1;
	}
	if (num_left > num_right + 1 || num_right > num_left + 1) {
		return -1;
	}
	return 1 + max(num_left, num_right);
}

bool isBalanced(TreeNode* root) {
	return isBalancedWithHeight(root) != -1;
}

int main() {
    TreeNode n0(0);
    cout << isBalanced(&n0) << " 1" << endl;

    TreeNode n1(1);
    n0.left = &n1;
    cout << isBalanced(&n0) << " 1" << endl;

    n0.left = NULL;
    n0.right = &n1;
    cout << isBalanced(&n0) << " 1" << endl;

    TreeNode n2(2);
    n0.left = &n1;
    n0.right = &n2;
    cout << isBalanced(&n0) << " 1" << endl;

    n0.right = NULL;
    n1.left = &n2;
    cout << isBalanced(&n0) << " 0" << endl;

    TreeNode n3(3);
    n0.right = &n3;
    cout << isBalanced(&n0) << " 1" << endl;

    TreeNode n4(4);
    n2.right = &n4;
    cout << isBalanced(&n0) << " 0" << endl;

    n1.right = &n4;
    cout << isBalanced(&n0) << " 0" << endl;
}