#include <vector>
#include <string>
#include <set>
using namespace std;

class NonDeterministicSubstring {
public:
  long long ways(string const &A,
             string const &B) {
  	set<string> MM;
  	int n = int(A.size());
  	int m = int(B.size());
  	for (int i = 0; i < n - m + 1; ++i) {
  		int j = 0;
  		for (; j < m; ++j) {
  			if (B[j] != '?' && B[j] != A[i + j]) {
  				break;
  			}
  		}
  		if (j == m) {
  			MM.insert(A.substr(i, m));
  		}
  	}
    return int(MM.size());
  }
};
