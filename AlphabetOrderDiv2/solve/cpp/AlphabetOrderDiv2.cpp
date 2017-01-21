#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class AlphabetOrderDiv2 {
public:
  string isOrdered(vector<string> const &words) {
  	unordered_map<char, unordered_set<char>> before;
  	for (string word: words) {
  		for (int i = 1; i < int(word.size()); i++) {
  			for (int j = 0; j < i; j++) {
  				char prev = word[j];
  				char cur = word[i];
  				if (prev == cur) {
  					continue;
  				}
  				if (before[prev].count(cur) == 1) {
  					return "Impossible";
  				}
  				before[cur].insert(prev);
  			}
  		}
  	}
    return "Possible";
  }
};
