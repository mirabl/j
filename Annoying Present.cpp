#include <bits/stdc++.h>

using namespace std;

long long minD(long long n) {
	if (n == 1) {
		return 0;
	} else if (n == 2) {
		return 1;
	}

	return n % 2 == 0 ? (n) * (n) / 4 : (((n) * (n)) - 1) / 4;
}

long long maxD(long long n) {
	return (n - 1) * (n) / 2.0;
}

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> x, d;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		x.push_back(tmp);
		cin >> tmp;
		d.push_back(tmp);
	}
	long long res = 0;
	auto smin = minD(n);
	auto smax = maxD(n);

	for (int i = 0; i < m; i++) {

		if (d[i] >= 0) {
			res += d[i] * smax;
		} else {
			res += d[i] * smin;
		}
		res += n * x[i];
	}

	cout << setprecision(7) << ((long double)res) / ((long double) n) << endl;
}