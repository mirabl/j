#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

class DoubleWeights {
public:
  int minw = -1;
  set<int> visited;

  // DFS all paths.
  void dfs(int from, int to, int w1cur, int w2cur, vector<string> const& weight1, vector<string> const& weight2) {
  	if (minw != -1 && (w1cur * w2cur) > minw || visited.count(from) == 1) { // Early abort with weights.
  		return;
  	}

  	if (from == to) {
  		if (minw == -1 || w1cur * w2cur < minw) {
  			minw = w1cur * w2cur;
  		}
  		return;
  	}

  	visited.insert(from);
  	for (int i = 0; i < int(weight1.size()); i++) {
  		if (weight1[from][i] != '.') {
			dfs(i, to, w1cur + int(weight1[from][i] - '0'), w2cur + int(weight2[from][i] - '0'), weight1, weight2);
  		}
  	}
  	visited.erase(from);
  }

  int minimalCost(vector<string> const &weight1,
                  vector<string> const &weight2) {
  	dfs(0, 1, 0, 0, weight1, weight2);
    return minw;
  }
};
