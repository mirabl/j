#include <vector>
#include <string>
using namespace std;

class ColorfulCoinsEasy {
public:
  string isPossible(vector<int> const &values) {
  	vector<int> div;
  	for (int i = 0; i < int(values.size()) - 1; i++) {
  		div.push_back(values[i + 1] / values[i]);
  	}
  	sort(div.begin(), div.end());

  	for (int i = 0; i < int(div.size()); i++) {
  		if (i + 1 >= div[i]) {
  			return "Impossible";
  		}
  	}
    return "Possible";
  }
};
