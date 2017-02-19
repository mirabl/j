#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

int height(TreeNode *r) {
	return (r ? 1 + max(height(r->left), height(r->right)) : 0);
}

void DFSinOrder(TreeNode *r) {
	if (r) {
		DFSinOrder(r->left);
		cout << r->val << " ";
		DFSinOrder(r->right);
	}
}

void BFS(TreeNode* r) {
	queue<TreeNode*> Q;
	Q.push(r);
	while (!Q.empty()) {
		TreeNode *n = Q.front();
		Q.pop();
		if (n) {
			cout << n->val << " ";
			Q.push(n->left);
			Q.push(n->right);
		}
	}
}


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

