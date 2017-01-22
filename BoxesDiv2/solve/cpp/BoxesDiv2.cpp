#include <vector>
#include <string>
using namespace std;

class BoxesDiv2 {
public:
  int nextPow2(int x) {
  	int y = 1;
  	while (y < x) {
  		y = y * 2;
  	}
  	return y;
  }
  
  int findSize(vector<int> const &candyCounts) {
  	vector<int> cC(candyCounts);
  	sort(cC.begin(), cC.end());
  	for (int i = 0; i < int(cC.size()); i++) {
  		cC[i] = nextPow2(cC[i]);
  	}

  	while (cC.size() != 1) {
  		cC[1] = nextPow2(cC[0] + cC[1]);
  		cC.erase(cC.begin());
  		sort(cC.begin(), cC.end());
  	}
    return cC[0];
  }
};
