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

/* BEGIN */

/*

void DFSinOrderIter(TreeNode *n) {

void DFSpreOrderIter(TreeNode *n) {

void DFSpostOrderIter(TreeNode *n) {

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

	cout << "\n\n[DFSinOrder]" << endl;
	DFSinOrderIter(&n0);
	cout << " == 6 3 1 0 4 2 5 7" << endl;


	cout << "\n\n[DFSpreOrder]" << endl;
	DFSpreOrderIter(&n0);
	cout << " == 0 1 3 6 2 4 5 7" << endl;

	cout << "\n\n[DFSpostOrder]" << endl;
	DFSpostOrderIter(&n0);
	cout << " == 6 3 1 4 7 5 2 0" << endl;

/*

    0
  1   2
 3   4 5
6       7  

*/

}


/* END */



/*
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) { }
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

void BFS(TreeNode* r) {
	queue<TreeNode*> Q;
	Q.push(r);
	while (!Q.empty()) {
		TreeNode *p = Q.front();
		Q.pop();
		if (p) {
			cout << p->val << " ";
			Q.push(p->left);
			Q.push(p->right);
		}
	}
}
*/