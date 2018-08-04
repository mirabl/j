// https://codeforces.com/contest/1011/problem/E

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp % k);
	}

	int g = a[0];
	for (auto x: a) {
		g = __gcd(g, x);
	}

	if (g == 0) {
		cout << "1" << endl;
		cout << "0" << endl;
		return 0;
	}

	vector<int> res{g};
	while (true) {
		int next = (res.back() + g) % k;
		if (next == g) {
			break;
		}
		res.push_back(next);
	}

	sort(res.begin(), res.end());

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << (i == 0 ? "" : " ");
		cout << res[i];
	}
	cout << endl;
}