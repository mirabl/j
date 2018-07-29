#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	map<int, int> bests;
	vector<int> w(v);
	sort(w.begin(), w.end());
	int totalProfit = 0;
	for (int i = 0; i < k; i++) {
		int profit = w[w.size() - 1 - i];
		totalProfit += profit;
		bests[profit]++;
	}

	vector<int> perDay;
	int day = 0;
	int end = -1;
	v.push_back(end);
	bests[end]++;
	bool first = true;
	for (int x: v) {
		if (bests[x] > 0) {
			if (!first) {
				perDay.push_back(day);
				day = 0;
			}
			first = false;
			bests[x]--;
		}
		day++;
	}

	cout << totalProfit << endl;
	for (int i = 0; i < perDay.size(); i++) {
		cout << (i > 0 ? " " : "");
		cout << perDay[i];
	}
	cout << endl;
}