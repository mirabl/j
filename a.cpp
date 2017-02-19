#include <vector>
#include <iostream>
using namespace std;
/*
Dynamic programming:
Given you can climb 1,2, or 3 stairs in one step, how many ways of reaching the top
	3 ways: bottom up (O(n) and O(1) space), top-down

How many ways to go from top left of a grid to bottom right of the grid with some obstacles in between
(cell == 0: free, cell == 1: obstacle)
*/



int stairsRec(int N, vector<int>& memo) {
	if (N < 0) {
		return 0;
	} else {
		if (memo[N] == -1) {
			memo[N] = stairsRec(N - 1, memo) + stairsRec(N - 2, memo) + stairsRec(N - 3, memo);
		}
		return memo[N];
	}
}

int stairsTopDown(int N) {
	vector<int> memo(N + 1, -1);
	memo[0] = 1;
	return stairsRec(N, memo);
}

int stairsDPNoStorage(int N) {
	int x = 1;
	int y = 1;
	int z = 2;

	if (N < 2) {
		return 1;
	} else {
		for (int i = 2; i < N; i++) {
			int t = x + y + z;
			x = y;
			y = z;
			z = t;
		}
	}

	return z;
}

int stairs(int N) {
	vector<int> A(max(N + 1, 3), 1);
	A[1] = 1;
	A[2] = 2;
	for (int i = 3; i <= N; i++) {
		A[i] = A[i - 3] + A[i - 2] + A[i - 1];
	}
	return A[N];
}

int gridWays(vector<vector<int>>& grid) {
	int nrows = grid.size();
	int ncols = grid[0].size();
	vector<vector<int>> A(nrows, vector<int>(ncols, 0));
	A[0][0] = (grid[0][0] == 0);
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

int gridWaysTopDownRec(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& A) {
	if (row < 0 || col < 0) {
		return 0;
	}
	if (A[row][col] == -1) {
		if (grid[row][col] == 0) {
			A[row][col] = gridWaysTopDownRec(grid, row - 1, col, A) + gridWaysTopDownRec(grid, row, col - 1, A);
		} else {
			A[row][col] = 0;
		}
	}
	return A[row][col];
}

int gridWaysTopDown(vector<vector<int>>& grid) {
	int nrows = grid.size();
	int ncols = grid[0].size();
	vector<vector<int>> A(nrows, vector<int>(ncols, -1));
	A[0][0] = (grid[0][0] == 0);
	return gridWaysTopDownRec(grid, nrows - 1, ncols - 1, A);
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

