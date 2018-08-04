// https://codeforces.com/contest/1011/problem/F
#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> ops;
vector<vector<int>> operands;

bool eval(int root) {
	if (ops[root] == "IN") {
		return operands[root][0];
	} else if (ops[root] == "NOT") {
		return eval(operands[root][0]) ^ 1;
	} else if (ops[root] == "XOR") {
		return eval(operands[root][0]) ^ eval(operands[root][1]);
	} else if (ops[root] == "OR") {
		return eval(operands[root][0]) | eval(operands[root][1]);
	}
	return eval(operands[root][0]) & eval(operands[root][1]); // AND
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;
		ops.push_back(op);
		int x;
		int y;
		if (op == "AND" || op == "XOR" || op == "OR") {
			cin >> x >> y;
			operands.push_back({x - 1, y - 1});
		} else if (op == "NOT") {
			cin >> x;
			operands.push_back({x - 1});
		} else {
			cin >> x;
			operands.push_back({x});
		}
	}

	for (int i = 0; i < n; i++) {
		if (ops[i] == "IN") {
			operands[i][0] ^= 1;
			bool r = eval(0);
			operands[i][0] ^= 1;
			cout << r;
		}
	}
	cout << endl;
}