/*
Dynamic programming:
Given you can climb 1,2, or 3 stairs in one step, how many ways of reaching the top
	3 ways: bottom up (O(n) and O(1) space), top-down

How many ways to go from top left of a grid to bottom right of the grid with some obstacles in between

*/
#include <iostream>
#include <vector>

using namespace std;

int stairs(int N) {
	int M[max(3, N + 1)];
	M[0] = 1;
	M[1] = 1;
	M[2] = 2;

	for (int i = 3; i < N + 1; i++) {
		M[i] = M[i - 3] + M[i - 2] + M[i - 1];
	}
	return M[N];
}

int stairsDPNoStorage(int N) {
	int M[3];
	M[0] = 1;
	M[1] = 1;
	M[2] = 2;
	for (int i = 3; i < N + 1; i++)  {
		int t = M[0] + M[1] + M[2];
		M[0] = M[1];
		M[1] = M[2];
		M[2] = t;
	}
	return M[min(N, 2)];
}


int stairsTopDownRec(int N, vector<int>& memo) {
	if (memo[N] != -1) {
		return memo[N];
	}
	int x = stairsTopDownRec(N - 3, memo) + stairsTopDownRec(N - 2, memo) + stairsTopDownRec(N - 1, memo);
	memo[N] = x;
	return x;
}

int stairsTopDown(int N) {
	vector<int> memo(max(3, N + 1), -1);
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	return stairsTopDownRec(N, memo);
}

/* ** */

int gridWays(vector<vector<int>>& grid) {
	int num_rows = int(grid.size());
	int num_cols = int(grid[0].size());
	int M[num_rows][num_cols];
	M[0][0] = 1;
	for (int row = 0; row < num_rows; row++) {
		for (int col = 0; col < num_cols; col++) {
			if (!(row == 0 && col == 0)) {
				M[row][col] = 0;
			}
			if (grid[row][col] == 0) {
				if (row > 0) {
					M[row][col] += M[row - 1][col];
				}
				if (col > 0) {
					M[row][col] += M[row][col - 1];
				}
			}
		}
	}

	return M[num_rows - 1][num_cols - 1];
}

int gridWaysTopDownRec(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& M) {
	int num_rows = int(grid.size());
	int num_cols = int(grid[0].size());
	if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
		return 0;
	}
	if (M[row][col] == -1) {
		int x;
		if (grid[row][col] == 0) {
			x = gridWaysTopDownRec(grid, row - 1, col, M) + gridWaysTopDownRec(grid, row, col - 1, M);
		} else {
			x = 0;
		}
		M[row][col] = x;
	}
	return M[row][col];
}

int gridWaysTopDown(vector<vector<int>>& grid) {
	int num_rows = int(grid.size());
	int num_cols = int(grid[0].size());
	vector<vector<int>> M(num_rows, vector<int>(num_cols, -1));
	M[0][0] = 1;
	return gridWaysTopDownRec(grid, num_rows - 1, num_cols - 1, M);
}

/* ********************************** */

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