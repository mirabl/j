/*
https://leetcode.com/problems/search-a-2d-matrix-ii/

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

alias c='g++ search_a_2d_matrix_ii.cpp -Wall -g'
alias a='c && ./a.out'

*/
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
	int n_rows = matrix.size();
	if (n_rows == 0) {
		return false;
	}
	int n_cols = matrix[0].size();
	if (n_cols == 0) {
		return false;
	}

	int row = 0;
	int col = n_cols - 1;
	while (true) {
		if (target == matrix[row][col]) {
			return true;
		} else if (target > matrix[row][col]) {
			row++;
		} else {
			col--;
		}
		if (row > n_rows - 1 || col < 0) {
			return false;
		}
	}
	return false; // Never reached.
}

int main() {
	vector<vector<int> > matrix;
	vector<int> row1;
	row1.push_back(1);
	row1.push_back(4);
	row1.push_back(7);
	row1.push_back(11);
	row1.push_back(15);
	matrix.push_back(row1);
	vector<int> row2;
	row2.push_back(2);
	row2.push_back(5);
	row2.push_back(8);
	row2.push_back(12);
	row2.push_back(19);
	matrix.push_back(row2);

	vector<int> row3;
	row3.push_back(3);
	row3.push_back(6);
	row3.push_back(9);
	row3.push_back(16);
	row3.push_back(22);
	matrix.push_back(row3);

	vector<int> row4;
	row4.push_back(10);
	row4.push_back(13);
	row4.push_back(14);
	row4.push_back(17);
	row4.push_back(24);
	matrix.push_back(row4);

	vector<int> row5;
	row5.push_back(18);
	row5.push_back(21);
	row5.push_back(23);
	row5.push_back(26);
	row5.push_back(30);
	matrix.push_back(row5);

	cout << searchMatrix(matrix, 5) << endl;
	cout << searchMatrix(matrix, 20) << endl;
	cout << searchMatrix(matrix, 200) << endl;
	cout << searchMatrix(matrix, 0) << endl;
	cout << searchMatrix(matrix, 15) << endl;
	cout << searchMatrix(matrix, 18) << endl;

	return 0;
}