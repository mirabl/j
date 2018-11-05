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
#include <map>
#include <set>
#include "exercise.hpp"

using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
	int L;
	cin >> L;
	int N;
	cin >> N;
	map<int, int> F;
	int res = 0;
	vector<int> V;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		V.push_back(t);
	}

	for (int i = 0; i < N; i++) {
		if (V[i] == L) {
			res++;
			continue;
		}
		for (int j = i + 1; j < N; j++) {
			if (V[i] + V[j] == L) {
				res++;
				V[i] = 0;
				V[j] = 0;
				break;
			}
		}
	}


	cout << res << endl;



    // BRUTEFORCE?

}