#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class ConnectedComponentConstruction {
public:
  vector<string> construct(vector<int> const &s) {
  	int N = int(s.size());
  	vector<string> M(N, string(N, 'N'));

  	unordered_map<int, vector<int>> nodesByCCCount;
  	for (int i = 0; i < N; i++) {
  		nodesByCCCount[s[i]].push_back(i);
  	}

  	for (auto it = nodesByCCCount.begin(); it != nodesByCCCount.end(); it++) {
  		int k = it->first;
  		int n = int(nodesByCCCount[k].size());
  		if (n % k != 0) {
  			return vector<string>();
  		}
  		for (int i = 0; i < n / k; i++) {
  			for (int j = 0; j < k; j++) {
  				for (int l = j + 1; l < k; l++) {
  					M[nodesByCCCount[k][i * k + j]][nodesByCCCount[k][i * k + l]] = 'Y';
  					M[nodesByCCCount[k][i * k + l]][nodesByCCCount[k][i * k + j]] = 'Y';
  				}
  			}
  		}
  	}
  	return M;
  }
};
