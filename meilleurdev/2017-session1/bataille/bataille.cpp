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

	map<int, vector<int>> vass;
	map<int, int> sz;

	set<int> visited;

int totsz(int root) {
	if (visited.count(root) == 1) {
		return 0;
	}
	visited.insert(root);
	int r = sz[root];
	for (int v: vass[root]) {
		r += totsz(v);
	}
	return r;
}

void ContestExerciseImpl::main() {
	int N;
	cin >> N;
	std::string line;

	std::getline(std::cin, line);

	for (int i = 0; i < N; i++) {
		std::getline(std::cin, line);
		istringstream iss(line);
		int trib;
		iss >> sz[i];
		int t;
		while (iss >> t) {
			vass[i].push_back(t);
		}

	}

	int m = 0;
	for (int i = 0; i < N; i++) {
		visited.clear();
		int tot = totsz(i);
		m = max(m, tot);
	}

	cout << m << endl;

    // BRUTEFORCE?

}