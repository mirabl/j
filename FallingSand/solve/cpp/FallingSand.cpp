#include <vector>
#include <string>
using namespace std;

class FallingSand {
public:
  vector<string> simulate(vector<string> const &board) {
  	int num_rows = int(board.size());
  	if (num_rows == 0) {
    	return vector<string>();
    }
    int num_cols = int(board[0].size());
    if (num_cols == 0) {
    	return board;
    }

    vector<string> A(board.begin(), board.end());

    for (int i = 0; i < num_rows; ++i) {
		for (int col = 0; col < num_cols; ++col) {
			for (int row = num_rows - 1; row > 0; --row) {
				if (A[row][col] == '.' && A[row - 1][col] == 'o') {
					A[row][col] = 'o';
					A[row - 1][col] = '.';
				} 
			}
		}
    }
	return A;
  }
};
