// https://codeforces.com/contest/1011/problem/F
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
vector<string> ops;
vector<vector<int>> operands;
map<int, int> parent;
vector<int> val;
int RECOMPUTE = -1;

bool eval(int root) {
    if (val[root] != RECOMPUTE) {
        return val[root];
    }

	if (ops[root] == "IN") {
		val[root] = operands[root][0];
	} else if (ops[root] == "NOT") {
        val[root] = eval(operands[root][0]) ^ 1;
	} else if (ops[root] == "XOR") {
		val[root] = eval(operands[root][0]) ^ eval(operands[root][1]);
	} else if (ops[root] == "OR") {
		val[root] = eval(operands[root][0]) | eval(operands[root][1]);
	} else {
	    val[root] = eval(operands[root][0]) & eval(operands[root][1]); // AND
    }

    return val[root];
}

void markRecompute(int root) {
    val[root] = RECOMPUTE;
    if (root != 0) {
        markRecompute(parent[root]);
    }
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
            parent[x - 1] = i;
            parent[y - 1] = i;
		} else if (op == "NOT") {
			cin >> x;
            parent[x - 1] = i;
            operands.push_back({x - 1});
		} else {
			cin >> x;
			operands.push_back({x});
		}
	}

    val = vector<int>(n, RECOMPUTE);

    eval(0);

	for (int i = 0; i < n; i++) {
		if (ops[i] == "IN") {
			operands[i][0] ^= 1;
            markRecompute(i);
			bool r = eval(0);
			operands[i][0] ^= 1;
            markRecompute(i);
			cout << r;
		}
	}
	cout << endl;
}
