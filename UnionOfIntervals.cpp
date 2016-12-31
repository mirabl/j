/*
https://community.topcoder.com/stat?c=problem_statement&pm=4823&rd=8074
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionOfIntervals {
public:
	// Line sweep. Unnecessary.
	int nthElement2(vector <int> lowerBound, vector <int> upperBound, int n) { 
	 	vector<pair<int, int>> events;
	 	int m = (int)lowerBound.size();
	 	const int kStart = 0;
	 	const int kStop = 1;
	 	for (int i = 0; i < m; ++i) {
	 		events.push_back(pair<int, int>(lowerBound[i], kStart));
	 		events.push_back(pair<int, int>(upperBound[i], kStop));
	 	}
	 	sort(events.begin(), events.end());
	 	int num_active = 0;
	 	int last_x = events[0].first;
	 	long long int cum = 0, last_cum = 0;
	 	vector<int> cumv;
	 	int i = 0;
	 	for (; i < (int)events.size(); ++i) {
// cout << "event " << (events[i].second == kStart ? "START " : "STOP ") << events[i].first << endl;
	 		last_cum = cum;
	 		cum += (((long long int)events[i].first - (long long int)last_x)) * (long long) num_active;
	 		if (cum > n) { // ?
// cout << "whoop last_x " << last_x << ", n-lcum=" << (n-last_cum) << " na " << num_active << endl;
	 			int y = last_x + (n - last_cum) / num_active;
	 			return y;
	 		}
	 		if (events[i].second == kStart) {
	 			num_active++;
	 		} else {
	 			num_active--;
	 			cum += 1;
	 		}
	 		last_x = events[i].first;
// cout << "c = " << cum << endl;
	 		cumv.push_back(cum);
	 	}
	 	return -1;
	 }


	 // Solution with binary search.
	long long index(int x, vector<int>& lowerBound, vector<int> upperBound) {
		long long idx = -1;
		for (int i = 0; i < (int)lowerBound.size(); ++i) {
			if (lowerBound[i] <= x && x <= upperBound[i]) {
				idx += (long long)x - (long long)lowerBound[i] + 1ll;
			} else if (upperBound[i] < x) {
				idx += (long long)upperBound[i] - (long long)lowerBound[i] + 1ll;
			}
		}
		return idx;
	}

	int nthElement(vector <int> lowerBound, vector <int> upperBound, int n) { 
		long long lo = *min_element(lowerBound.begin(), lowerBound.end());
		long long hi = *max_element(upperBound.begin(), upperBound.end());
		long long mid = lo + (hi - lo) / 2;
		long long idx = -1;
		while (lo < hi) {
			idx = index(mid, lowerBound, upperBound);
			// cout << "idx for " << mid << " is " << idx << endl;
			if (idx > n) {
				hi = mid;
			} else if (idx < n) {
				lo = mid + 1;
			} else {
				return mid;
			}
			mid = lo + (hi - lo) / 2;
		}
		return -1;
	}
};

int main() {
	UnionOfIntervals u;
	cout << u.nthElement(vector<int>{1, 5}, vector<int>{3, 7}, 4);
	cout <<  " 6" << endl;

	cout << u.nthElement(vector<int>{1, 3}, vector<int>{4, 5}, 3);
	cout <<  " 3" << endl;

	cout << u.nthElement(vector<int>{-1500000000}, vector<int>{1500000000}, 1500000091);
	cout <<  " 91" << endl;

	cout << endl;
}