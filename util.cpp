/*
alias a='g++ -Wall -std=c++11 util.cpp && ./a.out'
*/
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

void print_list(ListNode *n) {
	ListNode *p = n;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
}

void print_vector(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
}

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
	TreeNode n0(0);
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	n0.left = &n1;
	n1.left = &n2;
	n1.right = &n3;
	printTree(&n0);

}