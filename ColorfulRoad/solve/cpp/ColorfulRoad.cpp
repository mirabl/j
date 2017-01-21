#include <vector>
#include <string>
#include <map>
using namespace std;

class ColorfulRoad {
public:
  int getMin(string const &road) {
  	const int N = int(road.size()); // 2-15
  	const int INF = 1 << 28;
  	vector<vector<int>> M(N, vector<int>(N, INF));
  	map<char, char> allowed_next;
  	allowed_next['R'] = 'G';
  	allowed_next['G'] = 'B';
  	allowed_next['B'] = 'R';

  	for (int i = 0; i < N; i++) {
  		for (int j = i + 1; j < N; j++) {
  			if (allowed_next[road[i]] == road[j]) {
  				M[i][j] = (j - i) * (j - i);
  			}
  		}
  	}

  	// FW
  	for (int k = 0; k < N; k++) {
  		for (int i = 0; i < N; i++) {
  			for (int j = 0; j < N; j++) {
  				M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
  			}
  		}
  	}

    return (M[0][N-1] != INF ? M[0][N-1] : -1);
  }
};
