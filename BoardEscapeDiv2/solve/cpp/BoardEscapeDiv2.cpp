#include <vector>
#include <string>
using namespace std;
/*
	
{"T.#",
 "#.E"}
3
*/

class BoardEscapeDiv2 {
public:
  string findWinner(vector<string> const &s,
                    int kk) {
  	const int num_rows = int(s.size());
  	const int num_cols = int(s[0].size());

	// Could be more compact with only one array.
	// https://github.com/huntzhan/topcoder-env/blob/master/.vimcoder/13299/BoardEscapeDiv2.cc

  	bool AWinsAplays[num_rows][num_cols][kk + 1];
  	bool AWinsBplays[num_rows][num_cols][kk + 1];

  	int start_row = -1;
  	int start_col = -1;

  	for (int row = 0; row < num_rows; ++row) {
  		for (int col = 0; col < num_cols; ++col) {
  			AWinsBplays[row][col][0] = true;
  			AWinsAplays[row][col][0] = false;
  			if (s[row][col] == 'T') {
  				start_row = row;
  				start_col = col;
  			}
  		}
  	}

  	const int row_move[] = { -1, 1,  0, 0};
  	const int col_move[] = {  0, 0, -1, 1};

  	for (int k = 1; k < kk + 1; ++k) {
  		for (int row = 0; row < num_rows; ++row) {
  			for (int col = 0; col < num_cols; ++col) {
		  		if ((row > 0 && s[row - 1][col] == 'E')
		           || (row < num_rows - 1 && s[row + 1][col] == 'E')
		           || (col > 0 && s[row][col - 1] == 'E')
		           || (col < num_cols && s[row][col + 1] == 'E')) { // stuck.
					AWinsBplays[row][col][k] = false;
		  			AWinsAplays[row][col][k] = true;
		  			continue;
		  		}
		  		if (s[row][col] == 'E') {
		  			AWinsAplays[row][col][k] = false;
		  			AWinsBplays[row][col][k] = true;
		  			continue;
		  		}

		  		bool v = false;
		  		for (int dir = 0; dir < 4; ++dir) {
		  			int row2 = row + row_move[dir];
		  			int col2 = col + col_move[dir];
		  			if (row2 >= 0 && row2 < num_rows && col2 >= 0 && col2 < num_cols) {
		  				v = v || s[row2][col2] != '#' && AWinsBplays[row2][col2][k - 1];
		  			}
		  		}
		  		AWinsAplays[row][col][k] = v;

		  		v = true;
		  		for (int dir = 0; dir < 4; ++dir) {
		  			int row2 = row + row_move[dir];
		  			int col2 = col + col_move[dir];
		  			if (row2 >= 0 && row2 < num_rows && col2 >= 0 && col2 < num_cols) {
		  				v = v && AWinsAplays[row2][col2][k - 1];
		  			}
		  		}
		  		AWinsBplays[row][col][k] = v;
		  	}
		}
	}

	if (AWinsAplays[start_row][start_col][kk] == 1) {
		return "Alice";
	} else {
		return "Bob";
	}
  }
};
