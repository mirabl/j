/*
https://leetcode.com/problems/invert-binary-tree/
226. Invert Binary Tree   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 142522
Total Submissions: 287198
Difficulty: Easy
Contributors: Admin
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <utility>

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

void build_tree_from_vector(const vector<TreeNode*>& v) {
	int n = (int)v.size();
	for (int i = 1; i < n; ++i) {
		if (v[i] == NULL) {
			continue;
		}
		int parent = (i - 1) / 2;
		if ((i - 1) % 2 == 0) {
			v[parent]->left = v[i];
		} else {
			v[parent]->right = v[i];
		}
	}
}

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL) {
		return NULL;
	}
	swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

int main() {
	TreeNode n4(4);
	TreeNode n2(2);
	TreeNode n7(7);
	TreeNode n1(1);
	TreeNode n3(3);
	TreeNode n6(6);
	TreeNode n9(9);
	build_tree_from_vector(vector<TreeNode*>{&n4, &n2, &n7, &n1, &n3, &n6, &n9});
	printTree(&n4);
	invertTree(&n4);
	printTree(&n4);
}