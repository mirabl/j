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
#include "exercise.hpp"

using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void pg(vector<vector<char>>& g, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << g[i][j];
		}
		cout << endl;
	}
}
int row, col;

vector<pair<int, int>> dirs{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

bool dr(vector<vector<char>>& G, int N, int dir, int l) {
	for (int i = 0; i < l; i++) {
		G[row][col] = '#';
		if (i != l - 1) {
			row += dirs[dir].first;
			col += dirs[dir].second;
		}
		if (row < 0 || row >= N || col < 0 || col >= N) {
			return false;
		}
	}
	return true;
}

void ContestExerciseImpl::main() {
	int N;
	cin >> N;
	vector<vector<char>> G(N, vector<char>(N, '='));
    // BRUTEFORCE?

	int centerrow = N / 2;
	int centercol = N / 2;


	int dir = 0;
	int l = 2;

	row = centerrow;
	col = centercol;

	while (true) {
		bool cont = dr(G, N, dir, l);
//		cout << endl;
		if (!cont) {
			break;
		}
		dir = (dir + 1) % 4;
		l++;
	}

	pg(G, N);


}