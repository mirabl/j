#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

#define pii(x, y) pair<int, int>((x), (y))

class TriangleEasy {
public:
  int find(int n,
           vector<int> const &x,
           vector<int> const &y) {
  	set<pair<int, int>> edges;
  	for (int i = 0; i < int(x.size()); ++i) {
  		edges.insert(pii(min(x[i], y[i]), max(x[i], y[i])));
  	}
  	int m = 3;
  	for (int i = 0; i < n; ++i) {
  		for (int j = i + 1; j < n; ++j) {
  			for (int k = j + 1; k < n; ++k) {
  				int e = 3;
  				if (edges.count(pii(i, j)) == 1) {
  					e -= 1;
  				}
  				if (edges.count(pii(i, k)) == 1) {
  					e -= 1;
  				}
  				if (edges.count(pii(j, k)) == 1) {
  					e -= 1;
  				}
  				m = min(m, e);
  			}
  		}
  	}
    return m;
  }
};
