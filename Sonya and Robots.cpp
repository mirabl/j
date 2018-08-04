// https://codeforces.com/contest/1004/problem/C
// 1158

#include <bits/stdc++.h>

using namespace std;

int main()  {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	set<int> leftDone;
	vector<int> numDifferentFrom(n, 0);
	set<int> S;
	for (int i = n - 1; i >= 0; i--) {
		S.insert(a[i]);
		numDifferentFrom[i] = S.size();
	}

	long long res = 0;
	for (int i = 0; i < n - 1; i++) {
		if (leftDone.count(a[i]) == 1) {
			continue;
		}
		leftDone.insert(a[i]);

		res += numDifferentFrom[i + 1];
	}
	cout << res << endl;
}