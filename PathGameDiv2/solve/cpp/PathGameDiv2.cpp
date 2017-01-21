#include <vector>
#include <string>
using namespace std;

#define FREE(row, col) (board[(row)][(col)] == '.')

class PathGameDiv2 {
public:
  int calc(vector<string> const &board) {
  	int N = int(board[0].size());
  	vector<vector<int>> M(2, vector<int>(N));

	if (FREE(0, 0) && FREE(1, 0)) {
		M[0][0] = 1;
		M[1][0] = 1;
	}

  	for (int i = 1; i < N; i++) {
  		for (int col = 0; col < 2; col++) {
  			int m = 0;
			if (!FREE(col, i)) {
				M[col][i] = 0;
				continue;
			}
			if (FREE(col, i - 1)) {
				if (FREE(1 - col, i)) {
					m = max(m, M[col][i - 1] + 1);
				} else {
					m = max(m, M[col][i - 1]);
				}
			}
			if (FREE(1 - col, i - 1) && FREE(1 - col, i)) {
				m = max(m, M[1 - col][i - 1]);
			} 
	  		M[col][i] = m;
  		}
  	}
  	return max(M[0][N - 1], M[1][N - 1]);
  }
};
