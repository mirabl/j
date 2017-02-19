/*

*/
#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n / 2; i++) {
		swap(A[i], A[n - 1 - i]);
	}
}

/* BEGIN */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
void reverse(vector<int>& A) {
}
*/

int main() {
	srand(time(0));
	int n = 15 + (random() % 2);
	int m = 100;
	vector<int> A;
	for (int i = 0; i < n; i++) {
		A.push_back(random() % m);
	}
	vector<int> B(A);
	reverse(B.begin(), B.end());

	reverse(A);
	bool ok = true;
	for (int i = 0; i < n; i++) {
		ok = ok & (A[i] == B[i]);
	}
	cout << "[reverse]" << endl;
	cout << (ok ? "OK" : "NOK") << endl;
}

/* END */

