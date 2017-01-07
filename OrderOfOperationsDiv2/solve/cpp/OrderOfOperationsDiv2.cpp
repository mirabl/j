#include <vector>
#include <string>
using namespace std;

class OrderOfOperationsDiv2 {
public:
  int weight(string& a) {
  	int w = 0;
  	for(char c: a) {
  		if (c == '1') {
  			w += 1;
  		}
  	}
  	return w;
  }

  int minTime(vector<string> const &s) {
	vector<string> t(s);

	int n = int(s.size());
	int m = int(s[0].size());
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int min_weight = m;
		int min_idx = -1;
		for (int j = i; j < n; ++j) {
			int w = weight(t[j]);
			if (w <= min_weight) {
				min_weight = w;
				min_idx = j;
			}
		}
		string tmp = t[i];
		t[i] = t[min_idx];
		t[min_idx] = tmp;
		for (int j = i + 1; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (t[i][k] == '1' && t[j][k] == '1') {
					t[j][k] = '0';
				}
			}
		}
		res += min_weight * min_weight;
	}
	
    return res;
  }
};
