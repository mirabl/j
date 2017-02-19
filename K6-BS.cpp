/*

*/
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& A, int x) {
	int lo = 0;
	int hi = int(A.size()) - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (x == A[mid]) {
			return mid;
		} else if (x < A[mid]) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return -1;
}

/* BEGIN */
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/*
int binary_search(vector<int>& A, int x) {
}
*/

int main() {
	srand(time(0));
	int n = 15;
	int m = 100;
	vector<int> A;
	set<int> S;
	while (int(S.size()) != n) {
		S.insert(rand() % m);
	}
	A.insert(A.begin(), S.begin(), S.end());
	sort(A.begin(), A.end());
	int k = rand() % n;
	int Ak = A[k];
	cout << binary_search(A, Ak) << " " << k << endl;

	for (int i = 0; i < 10; i++) {
		int y = rand() % m;
		bool found = false;
		for (int x: A) {
			if (x == y) {
				found = true;
			}
		}
		if (!found) {
			cout << binary_search(A, y) << " " << -1 << endl;
			break;
		}
	}
}

/* END */

