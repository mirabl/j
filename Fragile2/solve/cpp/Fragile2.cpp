#include <vector>
#include <string>
#include <set>
using namespace std;

class Fragile2 {
public:
  void dfs(const vector<string>& graph, int from, set<int>& visited, int ignore1, int ignore2) {
  	if (from == ignore1 || from == ignore2 || visited.count(from) == 1) {
  		return;
  	}
  	visited.insert(from);
  	for (int i = 0; i < int(graph.size()); i++) {
  		if (graph[from][i] == 'Y') {
  			dfs(graph, i, visited, ignore1, ignore2);
  		}
  	}
  }

  // and ignore two vertices
  int count_connected_components(const vector<string>& graph, int ignore1, int ignore2) {
  	set<int> visited;
  	int cc = 0;
  	for (int i = 0; i < int(graph.size()); i++) {
  		if (i == ignore1 || i == ignore2) {
  			continue;
  		}
  		if (visited.count(i) == 0) {
  			dfs(graph, i, visited, ignore1, ignore2);
  			cc++;
  		}
  	}
  	return cc;
  }

  int countPairs(vector<string> const &graph) {

  	int cc = count_connected_components(graph, -1, -1);
  	int count = 0;
  	const int N = int(graph.size());
  	for (int i = 0; i < N; i++) {
  		for (int j = i + 1; j < N; j++) {
  			int cc2 = count_connected_components(graph, i, j);
  			if (cc2 > cc) {
  				count++;
	  		}
  		}
  	}

    return count;
  }
};
