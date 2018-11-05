/*******
 * Read input from cin
 * Use cout to output your result.
 * Use:
 *  localPrint( string mystring)
 * to display variable in a dedicated area.
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include "exercise.hpp"

using namespace std;

/*
2
2
20:10 1
20:16 1
*/

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

int totime(string s) {
	int h = 10 * (s[0] - '0') + s[1] - '0';
	int m = 10 * (s[3] - '0') + s[4] - '0';
	return 60 * h + m;
}

void ContestExerciseImpl::main() {
	int N;
	cin >> N;
	int X;
	cin >> X;
	vector<pair<int, int>> V;

	int pmax = 0;

	map<int, vector<int>> T;

	for (int i = 0; i < N; i++) {
		string h;
		cin >> h;
	//	cerr << "h=" << h << endl;
		int p;
		cin >> p;
	//	cerr << "p=" << p << endl;
		V.push_back({totime(h), p});
		pmax = max(pmax, p);
		T[p].push_back(totime(h));
  	}

	for (auto x: V) {
		//cerr << ",,," << x.first << " " << x.second << endl;
	}

	for (int p = 0; p <= pmax; p++) {
	//	cerr << "checking " << p << endl;

		auto v = T[p];
		for (auto y: v) {
//			cerr << "y:" << y << endl;
		}

		int n = v.size();
		for (int i = 0; i < n - 1; i++) {
			if (v[i + 1] - v[i] < 6) {
				cout << "COLLISION" << endl;
				return;
			}
		}

		for (int i = 0; i < n - X; i++) {
			if (v[i + X] - v[i] < 45) {
				cout << "COLLISION" << endl;
			}
		}

	}

	cout << "OK" << endl;

    // BRUTEFORCE?

}