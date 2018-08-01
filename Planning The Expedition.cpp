// http://codeforces.com/contest/1011/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;

	map<int, int> C;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		C[t]++;
	}

	for (int d = 100; d > 0; d--) {
		int S = 0;
		for (auto kvp: C) {
			S += kvp.second / d;
		}
		if (S >= n) {
			cout << d << endl;
			return 0;
		}
	}

	cout << 0 << endl;
}