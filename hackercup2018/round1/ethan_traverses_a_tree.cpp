/*
https://www.facebook.com/hackercup/problem/232395994158286/
alias a='g++ -Wall -std=c++11 ethan_traverses_a_tree.cpp'
alias b='./a.out < ethan_traverses_a_tree_sample_input.txt'

diff <(./a.out < ethan_traverses_a_tree_sample_input.txt) ethan_traverses_a_tree_sample_output.txt
paste -s <(./a.out < ethan_traverses_a_tree_sample_input.txt) ethan_traverses_a_tree_sample_output.txt


diff <(./a.out < ethan_traverses_a_tree.1.in) ethan_traverses_a_tree.1.out
paste -s <(./a.out < ethan_traverses_a_tree.1.in) ethan_traverses_a_tree.1.out

diff <(./a.out < ethan_traverses_a_tree.2.in) ethan_traverses_a_tree.2.out
paste -s <(./a.out < ethan_traverses_a_tree.2.in) ethan_traverses_a_tree.2.out



*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

/*
Input

Input begins with an integer T, the number of trees. For each tree, there is
first a line containing the space-separated integers N and K. Then, N lines
follow. The ith of these lines contains the space-separated integers Ai and
Bi.

Output

For the ith tree, print a line containing "Case #i: " followed by your chosen
node labels L1..N separated by spaces, or "Impossible" if there's no valid way
to label the nodes.

Constraints
1 ≤ T ≤ 80 
1 ≤ K ≤ N ≤ 2,000 
0 ≤ Ai, Bi ≤ N 

*/

void comp_pre(vector<int>& A, vector<int>& B, int root, vector<int>& pre) {
	if (root == 0) {
		return;
	}

	pre.push_back(root);
	comp_pre(A, B, A[root], pre);
	comp_pre(A, B, B[root], pre);
}

void comp_post(vector<int>& A, vector<int>& B, int root, vector<int>& post) {
	if (root == 0) {
		return;
	}

	comp_post(A, B, A[root], post);
	comp_post(A, B, B[root], post);
	post.push_back(root);
}

void pv(vector<int>& v) {
	for (auto x: v) {
		cerr << x << " ";
	}
}

int do_find(int a, vector<int>& UF) {
	if (UF[a] != a) {
		return do_find(UF[a], UF);
	}
	return a;
}
void do_union(int a, int b, vector<int>& UF) {
	UF[do_find(a, UF)] = do_find(b, UF);
}


int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		int K;
		cin >> N >> K;
		vector<int> A{-1};
		vector<int> B{-1};
		for (int n = 0; n < N; n++) {
			int a;
			int b;
			cin >> a >> b;
			A.push_back(a);
			B.push_back(b);
		}

		vector<int> pre;
		comp_pre(A, B, 1, pre);
		vector<int> post;
		comp_post(A, B, 1, post);


// pv(pre);
// cerr << endl;
// pv(post);
// cerr << endl;

		
		vector<int> UF;
		for (int i = 0; i < N; i++) {
			UF.push_back(i);
		}

		for (int i = 0; i < N; i++) {
			int a = pre[i] - 1;
			int b = post[i] - 1;
			do_union(a, b, UF);
		}


		unordered_map<int, vector<int>> H;
		for (int i = 0; i < N; i++) {
			H[do_find(i, UF)].push_back(i + 1);
		}

		vector<vector<int>> ccs;
		for (auto kvp: H) {
			auto cc = kvp.second;
			ccs.push_back(cc);
		}

// cerr << ccs.size() << endl;

		if (int(ccs.size()) < K) {
			cout << "Case #" << t << ": " << "Impossible" << endl; 
			continue;
		}

		vector<int> L(N);
		for (int j = 0; j < int(ccs.size()); j++) {
			for (int i: ccs[j]) {
				L[i - 1] = (j + 1 <= K) ? (j + 1) : 1;
			}
		}

// cerr << "L: "; pv(L); cerr << endl;

		cout << "Case #" << t << ":";
		for (auto x: L) {
			cout << " " << x;
		}
		cout << endl;
	}
}