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

vector<vector<int>> G;
	int N;

map<pair<int, int>, int> C;

int f(int row, int col) {
	if (C.count({row, col}) == 1) {
		return C[{row, col}];
	}

	if (row < 0 || row >= N || col < 0 || col >= N) {
		return 0;
	}
	int door = G[row][col];

	int a = f(row - 1, col);
	int b = f(row - 1, col - 1);
	int c = f(row, col - 1);
	C[{row, col}] = door + max(a, max(b, c));

			return C[{row, col}];

}

void ContestExerciseImpl::main() {
	cin >> N;
	G = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'X') {
				G[i][j] = 1;
			}
		}
	}

	int res = f(N - 1, N - 1);
	cout << res << endl;

    // BRUTEFORCE?

}