// https://www.facebook.com/hackercup/problem/175329729852444/
// alias a='g++ qualif_interception.cpp -Wall -std=c++11'
// alias b='./a.out < qualif_interception.in.1 '

#include <bits/stdc++.h>
using namespace std;
int main(void) {
	int T;

/* Input begins with an integer T, the number of polynomials. For each
polynomial, there is first a line containing the integer N, the degree of the
polynomial. Then, N+1 lines follow. The ith of these lines contains the
integer Pi-1. */


	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		int tmp;
		for (int i = 0; i <= N; i++) {
			cin >> tmp;
		}

/*         For the ith polynomial, print a line containing "Case #i: K", where
K is the number of distinct real values of x for which the polynomial
evaluates to 0. Then print K lines, each containing such a value of x, in
increasing order.
*/

		bool hasSolution = N % 2 == 1;

		cout << "Case #" << (t + 1) << ": " << (hasSolution ? 1 : 0) << endl;
		if (hasSolution) {
			cout << "0.0" << endl;
		}


	}
}