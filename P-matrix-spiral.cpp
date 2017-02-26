#include <iostream>
#include <vector>

using namespace std;

void spiral(const vector<vector<int>>& M) {
	int nrows = M.size();
	int ncols = M[0].size();
	int row_start = 0;
	int row_end = M.size() - 1;
	int col_start = 0;
	int col_end = M[0].size() - 1;
	cout << "******" << endl;
	while (row_start <= row_end || col_start <= col_end) {
		cout << "--" << endl;
		for (int col = col_start; row_start < nrows && col <= col_end; col++) {
			cout << M[row_start][col] << "a " << endl;
		}
		row_start++;

		for (int row = row_start; row <= row_end; row++) {
			cout << M[row][col_end] << "b " << endl;
		}
		col_end--;
		for (int col = col_end; row_end >= row_start && col >= col_start; col--) {
			cout << M[row_end][col] << "c " << endl;
		}
		row_end--;
		for (int row = row_end; col_start < ncols && col_start <= col_end && row >= row_start; row--) {
			cout << M[row][col_start] << "d " << endl;
		}
		col_start++;
	}
}

int main() {
	// vector<vector<int>> M{{1, 2, 3, 4}, {10, 11, 12, 5}, {9, 8, 7, 6}};
	// vector<vector<int>> M{{1, 2, 3, 4}};
	spiral({{1, 2, 3, 4}});
	spiral({{1}});
	spiral({{1, 2}});
	spiral({{1, 2}, {4, 3}});
	spiral({{1, 2, 3, 4}, {10, 11, 12, 5}, {9, 8, 7, 6}});
}