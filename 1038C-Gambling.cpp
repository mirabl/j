#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int play(vector<int>& a, vector<int>& b) {
	int score = 0;
	if (a.empty()) {
		b.pop_back();
	} else {
		if (b.empty() || a.back() >= b.back()) {
			score += a.back();
			a.pop_back();
		} else {
			b.pop_back();
		}
	}
	return score;
}

int main() {
	int n;
	cin >> n;
	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		b.push_back(t);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll scoreA = 0, scoreB = 0;
	while (!a.empty() || !b.empty()) {
		scoreA += play(a, b);
		scoreB += play(b, a);
	}

	cout << scoreA - scoreB << endl;
}