#include <vector>
#include <string>
#include <map>
using namespace std;

class MutaliskEasy {
public:
  map<vector<int>, int> memo; 	
  int solve_rec(vector<int>& x) {
  	if (memo.count(x) != 0) {
  		return memo[x];
  	}
  	if (x[0] == 0 && x[1] == 0 && x[2] == 0) {
  		return 0;
  	}
  	vector<int> y(3);
  	y[0] = max(0, x[0] - 9);
  	y[1] = max(0, x[1] - 3);
  	y[2] = max(0, x[2] - 1);
  	int n1 = 1 + solve_rec(y);

  	y[0] = max(0, x[0] - 9);
  	y[1] = max(0, x[1] - 1);
  	y[2] = max(0, x[2] - 3);
  	n1 = min(n1, 1 + solve_rec(y));

  	y[0] = max(0, x[0] - 3);
  	y[1] = max(0, x[1] - 9);
  	y[2] = max(0, x[2] - 1);
  	n1 = min(n1, 1 + solve_rec(y));

  	y[0] = max(0, x[0] - 3);
  	y[1] = max(0, x[1] - 1);
  	y[2] = max(0, x[2] - 9);
  	n1 = min(n1, 1 + solve_rec(y));

  	y[0] = max(0, x[0] - 1);
  	y[1] = max(0, x[1] - 9);
  	y[2] = max(0, x[2] - 3);
  	n1 = min(n1, 1 + solve_rec(y));

  	y[0] = max(0, x[0] - 1);
  	y[1] = max(0, x[1] - 3);
  	y[2] = max(0, x[2] - 9);
  	n1 = min(n1, 1 + solve_rec(y));

  	memo[x] = n1;

  	return n1;
  }

  int minimalAttacks(vector<int> const &x) {
  	vector<int> y(x);
  	while (int(y.size()) != 3) {
  		y.push_back(0);
  	}
  	return solve_rec(y);
  }
};
