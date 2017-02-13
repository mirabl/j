
#include <iostream>
#include <queue>
#include <stack>

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

void DFSinOrderIter(TreeNode *n) {
	if (!n) {
		return;
	}

	stack<TreeNode*> S;
	TreeNode *p;
	TreeNode *cur = n;

	while (cur || !S.empty()) {
		if (cur) {
			S.push(cur);
			cur = cur->left;
		} else {
			p = S.top();
			S.pop();
			cout << p->val << " ";
			cur = p->right;
		}
	}
}

void DFSpreOrderIter(TreeNode *n) {
	if (!n) { 
		return;
	}
	stack<TreeNode*> S;
	S.push(n);
	while (!S.empty()) {
		TreeNode *p = S.top();
		S.pop();
		if (!p) {
			continue;
		}
		cout << p->val << " ";
		S.push(p->right);
		S.push(p->left);
	}
}

void DFSpreOrder(TreeNode *n) {
	if (!n) {
		return;
	}
	cout << n->val << " ";
	DFSpreOrder(n->left);
	DFSpreOrder(n->right);
}

void DFSpostOrderIter(TreeNode *n) {
	stack<TreeNode*> S;
	stack<TreeNode*> T;
	T.push(n);
	while (!T.empty()) {
		TreeNode *p = T.top();
		T.pop();
		if (!p) {
			continue;
		}
		S.push(p);
		T.push(p->left);
		T.push(p->right);
	}
	while (!S.empty()) {
		cout << S.top()->val << " ";
		S.pop();
	}
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

/*
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// 1109
// 1137

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) { }
};

int height(TreeNode *r) {
	if (!r) { 
		return 0;
	}
	return 1 + max(height(r->left), height(r->right));
}

void DFSinOrder(TreeNode *r) {
	if (r) {
		DFSinOrder(r->left);
		cout << r->val << " ";
		DFSinOrder(r->right);
	}
}

void DFSinOrderIter(TreeNode *r) {
	TreeNode *cur;
	stack<TreeNode*> S;
	cur = r;
	while (cur || !S.empty()) {
		if (cur) {
			S.push(cur);
			cur = cur->left;
		} else {
			TreeNode *x = S.top();
			S.pop();
			cout << x->val << " ";
			cur = x->right;
		}
	}
}

void DFSpreOrder(TreeNode *r) {
	if (r) {
		cout << r->val << " ";
		DFSpreOrder(r->left);
		DFSpreOrder(r->right);
	}
}

void DFSpreOrderIter(TreeNode* r) {
	TreeNode *cur;
	stack<TreeNode*> S;
	cur = r;
	while (cur || !S.empty()) {
		if (cur) {
			cout << cur->val << " ";
			S.push(cur);
			cur = cur->left;
		} else {
			TreeNode *x = S.top();
			S.pop();
			cur = x->right;
		}
	}
}

void DFSpostOrder(TreeNode *r) {
	if (r) {
		DFSpostOrder(r->left);
		DFSpostOrder(r->right);
		cout << r->val << " ";
	}
}

void DFSpostOrderIter(TreeNode* r) {
	TreeNode *cur;
	stack<TreeNode*> S, T;

	S.push(r);
	while (!S.empty()) {
		TreeNode *x = S.top();
		S.pop();
		if (x) {
			S.push(x->left);
			S.push(x->right);
			T.push(x);
		}
	}


	while (!T.empty()) {
		cout << T.top()->val << " ";
		T.pop();
	}
}

void BFS(TreeNode* r) {
	queue<TreeNode*> Q;
	Q.push(r);
	while (!Q.empty()) {
		TreeNode *x = Q.front();
		Q.pop();
		if (x) {
			cout << x->val << " ";
			Q.push(x->left);
			Q.push(x->right);
		}
	}

}
*/

/* ******************************** */


/*

Trees:
structure
height
dfsinorder (rec, iter)
preorder
postorder
bfs


Check if tree is balanced
All traversals, recursive and iterative implementations
BFS/DFS
Construct a BST from a sorted array
Check if two trees are mirror image of each other
Find max path sum in the tree, negative nodes possible
Lowest common ancestor of 2 nodes in a tree

*/


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

	cout << "\n\n[height]" << endl;
	cout << height(&n0) << " == 4" << endl;

	cout << "\n\n[DFSinOrder]" << endl;
	DFSinOrder(&n0);
	cout << " == 6 3 1 0 4 2 5 7" << endl;

	DFSinOrderIter(&n0);
	cout << " == 6 3 1 0 4 2 5 7" << endl;


	cout << "\n\n[DFSpreOrder]" << endl;
	DFSpreOrder(&n0);
	cout << " == 0 1 3 6 2 4 5 7" << endl;
	DFSpreOrderIter(&n0);
	cout << " == 0 1 3 6 2 4 5 7" << endl;

	cout << "\n\n[DFSpostOrder]" << endl;
	DFSpostOrder(&n0);
	cout << " == 6 3 1 4 7 5 2 0" << endl;
	DFSpostOrderIter(&n0);
	cout << " == 6 3 1 4 7 5 2 0" << endl;

	cout << "\n\n[BFS]" << endl;
	BFS(&n0);
	cout << " == 0 1 2 3 4 5 6 7" << endl;


/*

    0
  1   2
 3   4 5
6       7  

*/

}


