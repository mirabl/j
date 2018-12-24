/*
https://leetcode.com/problems/valid-sudoku/
*/
bool isValidSudoku(vector<vector<char>>& board) {
	int n = 9;
	for (int row = 0; row < n; ++row) {
		set<int> S;
		for (int col = 0; col < n; ++col) {
			char v = board[row][col];
			if (v == '.') {
				continue;
			}
			if (S.count(v) == 1) {
				return false;
			}
			S.insert(v);
		}
	}

	for (int col = 0; col < n; ++col) {
		set<int> S;
		for (int row = 0; row < n; ++row) {
			char v = board[row][col];
			if (v == '.') {
				continue;
			}
			if (S.count(v) == 1) {
				return false;
			}
			S.insert(v);
		}
	}

	for (int row0 = 0; row0 < n; row0 += 3) {
		for (int col0 = 0; col0 < n; col0 += 3) {
			set<int> S;
			for (int row = row0; row < row0 + 3; ++row) {
				for (int col = col0; col < col0 + 3; ++col) {
					char v = board[row][col];
					if (v == '.') {
						continue;
					}
					if (S.count(v) == 1) {
						return false;
					}
					S.insert(v);
				}
			}

		}
	}
	return true;
}
