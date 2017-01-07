#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Quorum {
public:
  int count(vector<int> const &arr,
            int k) {
  	vector<int> A(arr);
  	sort(A.begin(), A.end());
  	int res = 0;
  	for (int i = 0; i < k; ++i) {
  		res += A[i];
  	}
    return res;
  }
};
