#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <set>
using namespace std;

class MazeWanderingEasy {
public:
  int decisions(vector<string> const &maze) {
  	int N = int(maze.size());
  	int M = int(maze[0].size());
  	int dec[N][M];
  	queue<pair<int, int>> Q;
  	for (int row = 0; row < N; row++) {
  		for (int col = 0; col < M; col++) {
  			if (maze[row][col] == 'M') {
  				Q.push({row, col});
				dec[row][col] = 0;
  			}
  		}
  	}

  	int drow[] = {-1, 1,  0, 0};
  	int dcol[] = { 0, 0, -1, 1};
  	set<pair<int, int>> visited;
  	while (!Q.empty()) {
  		int row = Q.front().first;
  		int col = Q.front().second;
  		Q.pop();
  		visited.insert({row, col});
  		if (maze[row][col] == '*') {
  			return dec[row][col];
  		}
  		int choices = 0;
  		for (int i = 0; i < 4; i++) {
  			int r = row + drow[i];
  			int c = col + dcol[i];
  			if (r < 0 || r >= N || c < 0 || c >= M
  				|| maze[r][c] == 'X' || visited.count({r, c}) == 1) {
  				continue;
  			}
  			Q.push({r, c});
  			choices++;
  		}
  		if (choices >= 2) {
  			dec[row][col]++;
  		}

  		for (int i = 0; i < 4; i++) {
  			int r = row + drow[i];
  			int c = col + dcol[i];
  			if (r < 0 || r >= N || c < 0 || c >= M
  				|| maze[r][c] == 'X' || visited.count({r, c}) == 1) {
  				continue;
  			}
  			dec[r][c] = dec[row][col];
  		}
  	}
  	return -1;  // Never reached.
  }
};


/*
class MazeWanderingEasy {
public:
  int decisions(vector<string> const &maze) {
  	int N = int(maze.size());
  	int M = int(maze[0].size());
  	int row_start = -1;
  	int col_start = -1;
  	int row_end = -1;
  	int col_end = -1;
  	for (int row = 0; row < N; row++) {
  		for (int col = 0; col < M; col++) {
  			if (maze[row][col] == 'M') {
  				row_start = row;
  				col_start = col;
  			}
  			if (maze[row][col] == '*') {
  				row_end = row;
  				col_end = col;
  			}
  		}
  	}

  	vector<vector<pair<int, int>>> prec(N, vector<pair<int, int>>(M));
  	queue<pair<int, int>> Q;
  	Q.push({row_start, col_start});
  	int drow[] = {-1, 1,  0, 0};
  	int dcol[] = { 0, 0, -1, 1};
  	set<pair<int, int>> visited;
  	while (!Q.empty()) {
  		int row = Q.front().first;
  		int col = Q.front().second;
  		Q.pop();
  		visited.insert({row, col});
  		if (row == row_end && col == col_end) {
  			break;
  		}
  		for (int i = 0; i < 4; i++) {
  			int r = row + drow[i];
  			int c = col + dcol[i];
  			if (r < 0 || r >= N || c < 0 || c >= M
  				|| maze[r][c] == 'X' || visited.count({r, c}) == 1) {
  				continue;
  			}
  			Q.push({r, c});
  			prec[r][c] = {row, col};
  		}
  	}

  	int r = row_end;
  	int c = col_end;
  	int choices = 0;
  	while (!(r == row_start && c == col_start)) {
  		pair<int, int> p = prec[r][c];
  		r = p.first;
  		c = p.second;
  		int possibilities = 0;
  		for (int i = 0; i < 4; i++) {
  			int r2 = r + drow[i];
  			int c2 = c + dcol[i];
  			if (r2 < 0 || r2 >= N || c2 < 0 || c2 >= M
  				|| maze[r2][c2] == 'X') {
  				continue;
  			}
  			possibilities++;
  		}
  		if (possibilities >= 3 || (r == row_start && c == col_start && possibilities >= 2)) {
  			choices++;
  		}
  	}

    return choices;
  }
};

*/