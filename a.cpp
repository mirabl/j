/* ********************************** */
#include <vector>
#include <iostream>
#include <map>
using namespace std;
/*
Dynamic programming:
Given you can climb 1,2, or 3 stairs in one step, how many ways of reaching the top
	3 ways: bottom up (O(n) and O(1) space), top-down

How many ways to go from top left of a grid to bottom right of the grid with some obstacles in between

*/



int stairs(int N) {
	vector<int> A(N + 1, 0);
	A[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3 && i - j >= 0; j++) {
			A[i] += A[i - j];
		}
	}
	return A[N];
}

int stairsDPNoStorage(int N) {
	if (N < 2) {
		return 1;
	}
	vector<int> A{1, 1, 2};
	for (int i = 0; i < N - 2; i++) {
		int tmp = A[0] + A[1] + A[2];
		A[0] = A[1];
		A[1] = A[2];
		A[2] = tmp;
	}
	return A[2];
}

int stairsTopDownRec(int N, map<int, int>& memo) {
	if (N < 0) {
		return 0;
	}
	if (memo.count(N) == 0) {
		int c = stairsTopDownRec(N - 1, memo) + stairsTopDownRec(N - 2, memo) + stairsTopDownRec(N - 3, memo);
		memo[N] = c;
	}
	return memo[N];
}

int stairsTopDown(int N) {
	map<int, int> memo{{0, 1}};
	return stairsTopDownRec(N, memo);
}

int gridWays(vector<vector<int>>& grid) {
	int nrows = grid.size();
	int ncols = grid[0].size();
	vector<vector<int>> A(nrows, vector<int>(ncols, 0));
	A[0][0] = grid[0][0] ^ 1;
	for (int row = 0; row < nrows; row++) {
		for (int col = 0; col < ncols; col++) {
			if (grid[row][col] == 1) {
				continue;
			}
			if (row > 0) {
				A[row][col] += A[row - 1][col];
			}
			if (col > 0) {
				A[row][col] += A[row][col - 1];
			}
		}
	}
	return A[nrows - 1][ncols - 1];
}

int gridWaysTopDownRec(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
	int nrows = grid.size();
	int ncols = grid[0].size();
	if (row < 0 || row >= nrows || col < 0 || col >= ncols) {
		return 0;
	}
	if (memo[row][col] == -1) {
		if (grid[row][col] == 1) {
			memo[row][col] = 0;
		} else {
			memo[row][col] = gridWaysTopDownRec(grid, row - 1, col, memo) + gridWaysTopDownRec(grid, row, col - 1, memo);
		}
	}
	return memo[row][col];
}

int gridWaysTopDown(vector<vector<int>>& grid) {
	int nrows = grid.size();
	int ncols = grid[0].size();
	vector<vector<int>> memo(nrows, vector<int>(ncols, -1));
	memo[0][0] = grid[0][0] ^ 1;
	return gridWaysTopDownRec(grid, nrows - 1, ncols - 1, memo);
}



int main() {
	int n = 8;
	cout << stairs(n) << " == 81 " << endl;
	cout << stairsDPNoStorage(n) << " == 81 " << endl;
	cout << stairsTopDown(n) << " == 81 " << endl;

	vector<vector<int>> grid{{0, 1},
							 {0, 0}};
	cout << gridWays(grid) << " == 1" << endl;
	cout << gridWaysTopDown(grid) << " == 1" << endl;


	vector<vector<int>> grid2{{0, 1},
							 {1, 0}};
	cout << gridWays(grid2) << " == 0" << endl;
	cout << gridWaysTopDown(grid2) << " == 0" << endl;


	vector<vector<int>> grid3{{0, 0},
							  {0, 0}};
	cout << gridWays(grid3) << " == 2" << endl;
	cout << gridWaysTopDown(grid3) << " == 2" << endl;


	vector<vector<int>> grid4{{0, 0, 0},
							  {0, 0, 0}};
	cout << gridWays(grid4) << " == 3" << endl;
	cout << gridWaysTopDown(grid4) << " == 3" << endl;



	vector<vector<int>> grid5{{0, 0, 1},
							  {0, 0, 0},
							  {1, 0, 0}};
	cout << gridWays(grid5) << " == 4" << endl;
	cout << gridWaysTopDown(grid5) << " == 4" << endl;
}