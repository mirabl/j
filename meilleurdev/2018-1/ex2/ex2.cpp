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

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}



int nn(vector<int>& V) {
	int res = 0;
	vector<int> d;
	int N = V.size();

	int baisse = 1;
	int monte = 2;
	int stable = 3;

	for (int i = 0; i < N - 1; i++) {
		int x = V[i + 1] - V[i];
		if (x > 0) {
			d.push_back(monte);
		} else if (x < 0) {
			d.push_back(baisse);
		} else {
			d.push_back(stable);
		}
	}

	for (int i = 0; i < int(d.size()) - 1; ) {
		if (d[i + 1] == monte && d[i] == baisse) {
			res++;
		}
		if (d[i + 1] == baisse && d[i] == monte) {
			res++;
		}
		if (d[i] == stable) {
			i += 2;
		} else {
			i++;
		}
	}
	return res;
}

void ContestExerciseImpl::main() {
	int N;
	cin >> N;
	vector<int> B, E;
	for (int i = 0; i < N; i++) {
		int b, e;
		cin >> b >> e;
	//	cout << "b=" << b << " e=" << e << endl;
		B.push_back(b);
		E.push_back(e);
	}

	int nB = nn(B);
	int nE = nn(E);

	if (nB < nE) {
		cout << "BITCOIN" << endl;
	} else if (nE > nB) {
		cout << "ETHEREUM" << endl;
	} else {
		cout << "KO" << endl;
	}

}