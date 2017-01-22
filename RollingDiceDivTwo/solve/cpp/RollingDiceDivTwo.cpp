#include <vector>
#include <string>
using namespace std;

class RollingDiceDivTwo {
public:
  int minimumFaces(vector<string> const &rolls) {
  	const int N = int(rolls[0].size());
  	vector<int> A(N, 1);
  	for (string roll: rolls) {
  		sort(roll.begin(), roll.end());
  		for (int i = 0; i < N; i++) {
  			A[i] = max(A[i], int(roll[i] - '0'));
  		}
  	}
  	int s = 0;
  	for (int x: A) {
  		s += x;
  	}
    return s;
  }
};
