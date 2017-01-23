#include <vector>
#include <string>
#include <cmath>
using namespace std;

class PillarsDivTwo {
public:
  double maximalLength(vector<int> const &height,
                       int w) {
  	vector<vector<double>> M(51, vector<double>(100, 0.0));
  	for (int i = 1; i < int(height.size()); i++) {
  		for (int j = 1; j < height[i] + 1; j++) {
  			for (int k = 1; k < height[i - 1] + 1; k++) {
  				M[i][j] = max(M[i][j], M[i - 1][k] + sqrt(double(w * w) + ((k - j) * (k - j))));
  			}
  		}
  	}
    double m = 0;
    for (int i = 1; i < height[height.size() - 1] + 1; i++) {
    	m = max(m, M[height.size() - 1][i]);
    }
    return m;
  }
};
