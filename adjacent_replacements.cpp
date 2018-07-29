// Adjacent Replacements
// http://codeforces.com/contest/1006/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (i != 0) {
			cout << " ";
		}
		cout << (tmp % 2 == 0 ? tmp - 1 : tmp);
	}
}