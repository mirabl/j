#include <vector>
#include <string>
#include <set>
using namespace std;

// Could be shorted with implicit graph.

class ArcadeManao {
public:
  bool dfs(int from, int to, int maxladder, vector<vector<int>>& G, set<int>& visited) {
  	if (to == from) {
  		return true;
  	}
  	visited.insert(from);
  	for (int i = 0; i < int(G[from].size()); i++) {
  		if (visited.count(i) == 0 && G[from][i] != -1 
  			&& G[from][i] <= maxladder && dfs(i, to, maxladder, G, visited)) {
  			return true;
  		}
  	}
  	return false;
  }

  int shortestLadder(vector<string> const &level,
                     int coinRow,
                     int coinColumn) {

  	int N = int(level.size());
  	int M = int(level[0].size());
  	vector<vector<int>> grid(N, vector<int>(M, -1));
  	int cur = 0;
  	for (int row = 0; row < N; row++) {
  		int col = 0;
  		while (col < M) {
	  		while (col < M && level[row][col] != 'X') {
	  			col++;
	  		}
	  		if (col == M) {
	  			break;
	  		}
	  		while (level[row][col] == 'X') {
	  			grid[row][col] = cur;
	  			col++;
	  		}
	  		cur++;
  		}
  	}

  	int num_platforms = cur;
  	vector<vector<int>> G(num_platforms, vector<int>(num_platforms, -1));

  	for (int col = 0; col < M; col++) {
  		for (int row = 0; row < N; row++) {
  			for (int row2 = row + 1; row2 < N; row2++) {
  				if (grid[row][col] != -1 && grid[row2][col] != -1) {
  					G[grid[row][col]][grid[row2][col]] = row2 - row;
  					G[grid[row2][col]][grid[row][col]] = row2 - row;
  				}
  			}
  		}
  	}

  	for (int l = 0; l < 55; l++) {
	  	set<int> visited;
  		if (dfs(grid[N - 1][0], grid[coinRow - 1][coinColumn - 1], l, G, visited)) {
  			return l;
  		}
  	}

    return 0;
  }
};
