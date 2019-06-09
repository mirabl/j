/*
https://leetcode.com/problems/same-tree/
100. Same Tree   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 173141
Total Submissions: 383669
Difficulty: Easy
Contributors: Admin
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

alias a='g++ -Wall -std=c++11 same_tree.cpp && ./a.out'
*/
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) { }
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL || q == NULL) {
		return p == q;
	}
	return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
	cout << isSameTree(NULL, NULL) << " 1" << endl;

	TreeNode n0(0);
	cout << isSameTree(&n0, NULL) << " 0" << endl;
	cout << isSameTree(NULL, &n0) << " 0" << endl;

	cout << isSameTree(&n0, &n0) << " 1" << endl;
	TreeNode n0b(0);
	cout << isSameTree(&n0, &n0b) << " 1" << endl;

	TreeNode n1(1);
	cout << isSameTree(&n0, &n1) << " 0" << endl;
	n0.right = &n1;
	cout << isSameTree(&n0, &n1) << " 0" << endl;
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return !p && !q;
        }
        
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
