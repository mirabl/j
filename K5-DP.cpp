/*

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



/* BEGIN */
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

/*

int stairs(int N) {

}

int stairsDPNoStorage(int N) {

}

int stairsTopDown(int N) {

}

int gridWays(vector<vector<int>>& grid) {

}

int gridWaysTopDown(vector<vector<int>>& grid) {

}

*/

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

/* END */


/*
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

*/
