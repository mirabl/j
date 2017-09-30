#include <iostream>
#include <vector>
using namespace std;


// Always one solution.

void printGrid(vector<vector<int>>& G) {
	for (int row = 0; row < 9; row++) {
	    for (int col = 0; col < 9; col++) {
	        cout << G[row][col] << " ";
	    }
	    cout << endl;
	}
}

bool validRow(vector<vector<int>>& G, int row) {
	vector<bool> exists(10, false);
	for (int col = 0; col < 9; col++) {
		if (G[row][col] == 0) {
			continue;
		}
		if (exists[G[row][col]]) {
			return false;
		}
		exists[G[row][col]] = true;
	}
	return true;
}

bool validCol(vector<vector<int>>& G, int col) {
	vector<bool> exists(10, false);
	for (int row = 0; row < 9; row++) {
		if (G[row][col] == 0) {
			continue;
		}
		if (exists[G[row][col]]) {
			return false;
		}
		exists[G[row][col]] = true;
	}
	return true;
}

bool validSquare(vector<vector<int>>& G, int row, int col) {
	int square_nw_row = 3 * (row / 3);
	int square_nw_col = 3 * (col / 3);

	vector<bool> exists(10, false);
	for (int r = square_nw_row; r < square_nw_row + 3; r++) {
		for (int c = square_nw_col; c < square_nw_col + 3; c++) {
			if (G[r][c] == 0) {
				continue;
			}
			if (exists[G[r][c]]) {
				return false;
			}
			exists[G[r][c]] = true;
		}
	}
	return true;
}

bool findCell(vector<vector<int>>& G, pair<int, int>& cell, vector<int>& best_values) {
	cell.first = -1;
	for (int row = 0; row < 9; row++) {	
		for (int col = 0; col < 9; col++) {

			if (G[row][col] == 0) {
				for (int v = 1; v <= 9; v++) {
					G[row][col] = v;
					if (validRow(G, row) && validCol(G, col) && validSquare(G, row, col)) {
						best_values.push_back(v);
					}
					G[row][col] = 0;
				}
				if (best_values.empty()) {
					cell.first = -1;
				} else {
					cell.first = row;
					cell.second = col;
				}
				return false;				
			}
		}
	}
	return true;
}

bool fillCell(vector<vector<int>>& G) {
	/* find cell (if no cell return false)
	   for each possible value
	      copy G
	      set the value
	      if (fillCell) 
			return true
		return false
    */
    pair<int, int> cell;
    vector<int> values;

    if (findCell(G, cell, values)) {
    	return true;
    } else if (cell.first == -1) {
    	return false;
    }

    for (int value: values) {
    	G[cell.first][cell.second] = value;
    	if (fillCell(G)) {
    		return true;
    	}
    	G[cell.first][cell.second] = 0;
    }
    return false;
}

void solveSudoku(vector<vector<int>>& G) {
	fillCell(G);
}

void printAnswer(vector<vector<int>>& G) {
	for (int row = 0; row < 9; row++) {
	    for (int col = 0; col < 9; col++) {
	        cout << G[row][col] << " ";
	    }
	}
	cout << endl;
}

int main() {
	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {
		vector<vector<int>> G(9, vector<int>(9));
		for (int row = 0; row < 9; row++) {
		    for (int col = 0; col < 9; col++) {
		        cin >> G[row][col];
		    }
		}

		solveSudoku(G);
		printAnswer(G);
	}		
	return 0;
}








// Probably buggy. Does TLE on GFG online judge.
bool findCell2(vector<vector<int>>& G, pair<int, int>& cell, vector<int>& best_values) {
	int best_row = -1;
	int best_col = -1;
	bool all_cell_filled = true;
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (G[row][col] == 0) {
				all_cell_filled = false;
				vector<int> values;
				for (int v = 1; v <= 9; v++) {
					G[row][col] = v;
					if (validRow(G, row) && validCol(G, col) && validSquare(G, row, col)) {
						values.push_back(v);
					}
				}
				if (best_values.empty() || best_values.size() > values.size()) {
					swap(best_values, values);
					best_row = row;
					best_col = col;
				}
				G[row][col] = 0;
			}
		}
	}
	cell.first = best_row;
	cell.second = best_col;

	return all_cell_filled;
}
