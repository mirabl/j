/*
Trees:
Check if tree is balanced
All traversals, recursive and iterative implementations
BFS/DFS
Construct a BST from a sorted array
Check if two trees are mirror image of each other
Find max path sum in the tree, negative nodes possible
Lowest common ancestor of 2 nodes in a tree

*/
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) { }
};

// Off by +1?
int height(TreeNode *n) {
	if (n == NULL) { 
		return 0;
	}
	return 1 + max(height(n->left), height(n->right));
}

void DFSinOrder(TreeNode *n) {
	if (!n) {
		return;
	}
	DFSinOrder(n->left);
	cout << n->val << " ";
	DFSinOrder(n->right);
}

void DFSpreOrder(TreeNode *n) {
	if (!n) {
		return;
	}
	cout << n->val << " ";
	DFSpreOrder(n->left);
	DFSpreOrder(n->right);
}

void DFSpostOrder(TreeNode *n) {
	if (!n) {
		return;
	}
	DFSpostOrder(n->left);
	DFSpostOrder(n->right);
	cout << n->val << " ";
}

void BFS(TreeNode *n) {
	queue<TreeNode*> Q;
	Q.push(n);
	while (!Q.empty()) {
		TreeNode *p = Q.front();
		Q.pop();
		if (!p) {
			continue;
		}
		cout << p->val << " ";
		Q.push(p->left);
		Q.push(p->right);
	}
}

/* ******************************** */

int main() {
	TreeNode n0(0);
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);

	n0.left = &n1;
	n0.right = &n2;
	n1.left = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n5.right = &n7;

	cout << height(&n0) << " == 4" << endl;

	DFSinOrder(&n0);
	cout << " == 6 3 1 0 4 2 5 7" << endl;

	DFSpreOrder(&n0);
	cout << " == 0 1 3 6 2 4 5 7" << endl;

	DFSpostOrder(&n0);
	cout << " == 6 3 1 4 7 5 2 0" << endl;


	BFS(&n0);
	cout << " == 0 1 2 3 4 5 6 7" << endl;


/*

    0
  1   2
 3   4 5
6       7  

*/

}