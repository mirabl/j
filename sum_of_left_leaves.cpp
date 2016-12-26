/*
https://leetcode.com/problems/sum-of-left-leaves/
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

alias a='g++ -Wall -g sum_of_left_leaves.cpp && ./a.out'

*/
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

int sum_of_left_leaves(TreeNode *root, bool is_left) {
	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL && root->right == NULL) { // Leaf.
		if (is_left) {
			return root->val;
		} else {
			return 0;
		}
	} else {
		return sum_of_left_leaves(root->left, true) + sum_of_left_leaves(root->right, false);
	}
}

int sumOfLeftLeaves(TreeNode* root) {
    return sum_of_left_leaves(root, false);
}


int main() {
	TreeNode n3(3);
	TreeNode n9(9);
	TreeNode n20(20);
	TreeNode n15(15);
	TreeNode n7(7);

	n3.left = &n9;
	n3.right = &n20;
	n20.left = &n15;
	n20.right = &n7;

	cout << sumOfLeftLeaves(&n3) << endl;

}