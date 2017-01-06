#include <vector>
#include <string>
#include <set>
using namespace std;

class GridSort {
public:
  string sort(int n,
              int m,
              vector<int> const &grid) {
  	int num_rows = n;
  	int num_cols = m;
  	set<set<int>> row_sets;
  	set<set<int>> expected_row_sets;
  	for (int row = 0; row < num_rows; ++row) {
  		set<int> S;
  		set<int> T;
  		for (int col = 0; col < num_cols; ++col) {
  			S.insert(grid[row * num_cols + col]);
  			T.insert(row * num_cols + col + 1);
  		}
  		row_sets.insert(S);
  		expected_row_sets.insert(T);
  	}

  	if (row_sets != expected_row_sets) {
  		return string("Impossible");
  	}

  	set<set<int>> col_sets;
  	set<set<int>> expected_col_sets;
	for (int col = 0; col < num_cols; ++col) {
  		set<int> S;
  		set<int> T;
  		for (int row = 0; row < num_rows; ++row) {
  			S.insert(grid[row * num_cols + col]);
  			T.insert(row * num_cols + col + 1);
  		}
  		col_sets.insert(S);
  		expected_col_sets.insert(T);
  	}

  	if (col_sets != expected_col_sets) {
  		return string("Impossible");
  	}

    return string("Possible");
  }
};
