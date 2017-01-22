#include <vector>
#include <string>
using namespace std;

class JumpFurther {
public:
  int furthest(int N,
               int badStep) {
  	int s = 0;
  	for (int i = 1; i <= N; i++) {
  		s += i;
  		if (s == badStep) {
  			return ((N *(N + 1)) / 2) - 1;
  		}
  	}
  	return (N * (N  + 1)) / 2;
  }
};
