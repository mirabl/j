#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cassert>
using namespace std;

// Can be simplified if problem is analyzed correctly.

class CirclesCountry {
public:
  bool isCircleContained(int xa, int ya, int ra, int xb, int yb, int rb) {
  	if (ra >= rb) {
  		return false;
  	}
  	return ((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)) < rb * rb;
  }

  int findSmallestCircleExcept(int x, int y, int r,
  					     vector<int> const &X,
	                     vector<int> const &Y,
	                     vector<int> const &R) {
  	int N = int(X.size());
  	int min_circle = -1;
  	for (int i = 0; i < N; i++) {
  		if ((min_circle == -1 || R[i] < R[min_circle])
  			&& isCircleContained(x, y, r, X[i], Y[i], R[i])) {
  			min_circle = i;
  		}
  	}
  	assert(min_circle != -1);
  	return min_circle;  // Always exists.
  }

  int leastBorders(vector<int> const &X,
                   vector<int> const &Y,
                   vector<int> const &R,
                   int x1,
                   int y1,
                   int x2,
                   int y2) {

  	vector<int> XX(X);
  	vector<int> YY(Y);
  	vector<int> RR(R);

  	XX.push_back(0); // Master circle.
  	YY.push_back(0);
  	RR.push_back(3000);  

  	int N = int(XX.size());
  	vector<vector<int>> adj(N);
  	for (int i = 0; i < N - 1; i++) {
  		int c = findSmallestCircleExcept(XX[i], YY[i], RR[i], XX, YY, RR);
  		adj[i].push_back(c);
  		adj[c].push_back(i);
  	}

  	int circle_start = findSmallestCircleExcept(x1, y1, 0, XX, YY, RR);
  	int circle_end = findSmallestCircleExcept(x2, y2, 0, XX, YY, RR);

  	queue<int> Q;
  	set<int> visited;
  	Q.push(circle_start);
  	Q.push(-1);
 	int d = 0;
  	while (!Q.empty()) {
  		int c = Q.front();
  		Q.pop();
  		if (visited.count(c) == 1) {
  			continue;
  		}
  		if (c == -1) {
  			d++;
  			if (!Q.empty()) {
  				Q.push(-1);
  			}
  			continue;
  		}
  		if (c == circle_end) {
  			return d;
  		}
  		for (int v: adj[c]) {
  			Q.push(v);
  		}
  		visited.insert(c);
  	}

    return -1; // Never reached.
  }
};
