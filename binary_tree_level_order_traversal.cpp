/*
https://leetcode.com/problems/binary-tree-level-order-traversal/

*/
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) { }
};

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (root == NULL) {
		return res;
	}
	queue<TreeNode*> Q;
	Q.push(root);
	Q.push(NULL);
	vector<int> current_level;
	while (!Q.empty()) {
		TreeNode *n = Q.front();
		Q.pop();
		if (n == NULL) {
			res.push_back(current_level);
			current_level.resize(0); 
			if (!Q.empty()) {
				Q.push(NULL);
			}
		} else {
			current_level.push_back(n->val);
			if (n->left)  {
				Q.push(n->left);
			}
			if (n->right) {
				Q.push(n->right);
			}
		}
	}
	return res;
}

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

void build_tree_from_array(TreeNode* v[], int n) {
	for (int i = 1; i < n; ++i) {
		if (v[i] == NULL) {
			continue;
		}
		int parent = (i - 1) / 2;
		if (i % 2 == 1) {
			if (v[parent] != NULL) {
				v[parent]->left = v[i];
			}
		} else {
			if (v[parent] != NULL) {
				v[parent]->right = v[i];
			}
		}
	}
}


int main() {

	TreeNode* x[] = {new TreeNode(3), new TreeNode(9), new TreeNode(20),
	                 NULL, NULL, new TreeNode(15), new TreeNode(7)};
	build_tree_from_array(x, 7);
	// [3,9,20,null,null,15,7]
	printTree(x[0]);

	vector<vector<int>> order = levelOrder(x[0]);
	for (int i = 0; i < (int)order.size(); ++i) {
		cout << "[";
		for (int j = 0; j < (int)order[i].size(); ++j) {
			cout << order[i][j] << " ";
		}
		cout << endl;
	}
}