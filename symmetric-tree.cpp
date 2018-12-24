/*
https://leetcode.com/problems/symmetric-tree/
101. Symmetric Tree   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 147373
Total Submissions: 400415
Difficulty: Easy
Contributors: Admin
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <iostream>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) { }
};
int depth(TreeNode *n) {
	if (n == NULL) {
		return 0;
	}
	return 1 + max(depth(n->left), depth(n->right));
}


// Naive.
void printTree(TreeNode *n) {
	int d = depth(n);
	queue<TreeNode*> Q;
	Q.push(n);
	int node_num = 0;
	int level = 0;
	int count_in_level = 0;
	while (!Q.empty()) {
		TreeNode *p = Q.front();
		Q.pop();
		int lp = d - level - 1;
		if (count_in_level == 0) {
			// cout << "                        entering lp " <<  lp << " " << "d=" << d << endl;
			for (int i = 0; i < (1 << lp) - 1; ++i) {
				cout << " ";
			}
		}
		if (p != NULL) {
			cout << p->val;
		} else {
			cout << " ";

		}

		if (p != NULL) {
			Q.push(p->left);
			Q.push(p->right);
		}
		node_num++;
		count_in_level++;
		if (count_in_level == (1 << level)) {
			level++;
			count_in_level = 0;
			cout << endl;
			if (level == d) {
				break;
			}
		} else {
			for (int i = 0; i < (1 << (lp + 1)) - 1; ++i) {
				cout << " ";
			}
		}
	}
}

bool recCheck(TreeNode *a, TreeNode *b) {
	if (a == NULL || b == NULL) {
		return a == b;
	}
	if (a->val != b->val) {
		return false;
	}
	return recCheck(a->left, b->right) && recCheck(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
	return recCheck(root, root);
}

int main() {
	TreeNode nA(1);
	TreeNode nB(2);
	TreeNode nC(2);
	TreeNode nD(3);
	TreeNode nE(4);
	TreeNode nF(4);
	TreeNode nG(3);
	nA.left = &nB;
	nA.right = &nC;
	nB.left = &nD;
	nB.right = &nE;
	nC.left = &nF;
	nC.right = &nG;

	printTree(&nA);

	cout << isSymmetric(&nA);
}
