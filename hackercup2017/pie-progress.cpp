/*
alias a='g++ pie-progress.cpp  -Wall -std=c++11'
alias b='./a.out < pie-progress.in.0'
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define INFTY (1000100)

void print_vec(vector<ll>& v) {
	for (auto x: v) {
		cout << x << " ";
	}
	cout << endl;
}

ll PriceToBuy(int day, int buy, vector<vector<ll> >& C) {
	ll s = 0;

	if (buy >= int(C.size())) {
		return INFTY;
	}

	for (int i = 0; i < buy; i++) {
		s += C[day][i];
	}
	s += buy * buy;
	return s;
}

// min to pay when day finished
ll MinPay(int day, int left, vector<vector<ll> >& C) {
	if (day == -1) {
		return left == 0 ? 0 : INFTY;
	}

	ll best = INFTY;
	for (int buy_today = 0; buy_today <= left + 1; buy_today++) {
		best = min(best, MinPay(day - 1, left - buy_today + 1, C) + PriceToBuy(day, buy_today, C));
//cout << "buy_today=" << buy_today << ", " << "best=" << best << endl;
	}
	return best;
}

int main() {
	/*
	Input

Input begins with an integer T, the number of times you go on a pie-eating
spree. For each case, there is first a line containing two space-separated
integers, N and M. Then, N lines follow, each containing M space-separated
integers. The jth integer on the ith line is Ci,j.

Output

For the ith case, print a line containing "Case #i: " followed by the minimum
you need to pay to eat a pie every day. 
*/

	int T;
	cin >> T;

	for (int t = 1; t < T + 1; t++) {
		int N, M;
		cin >> N >> M;
		vector<vector<ll> > C;
		for (int n = 0; n < N; n++) {
			vector<ll> row;
			for (int m = 0; m < M; m++) {
				int x;
				cin >> x;
				row.push_back(x);
			}
			sort(row.begin(), row.end());
			C.push_back(row);
		}


		ll res = MinPay(N - 1, 0, C);

		cout << "Case #" << t << ": " << res << endl;  
	}
}