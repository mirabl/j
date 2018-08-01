// http://codeforces.com/contest/1011/problem/C

#include <bits/stdc++.h>

using namespace std;

bool canFly(int n, int m, vector<int>& a, vector<int>& b, double f) {
	double cur = double(m) + f;

	// take off 1
	cur -= cur / a[0];

	for (int i = 1; i < n; i++) {
		cur -= cur / b[i];
		cur -= cur / a[i];
	}

	// land 1
	cur -= cur / b[0];
	return cur >= m;
}

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	vector<int> b;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	double lo = 0;
	double hi = 1 + 1e9;
	double e = 1e-7;

	bool found = false;
	 while (hi > lo + e) {
		double mid = (lo + hi) / 2.0;
		bool can = canFly(n, m, a, b, mid);
		if (!can) {
			lo = mid + e;
		} else {
			hi = mid;
			found = true;
		}
	}

	cout << std::setprecision(8) << (found ? hi : -1) << endl;
}