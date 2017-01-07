#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class Quacking {
public:
  int quack(string const &s) {
  	const char END = 'k';
  	const char START = 'q';
  	map<char, char> prev;
  	prev['u'] = 'q';
  	prev['a'] = 'u';
  	prev['c'] = 'a';
  	prev['k'] = 'c';

  	map<char, int> stacks;

  	int num_active = 0;
  	int min_num_active = 0;
  	for(char c: s) {
  		if (c == START) {
  			num_active++;
  			stacks[c]++;
  		} else {
  			char p = prev[c];
  			if (stacks[p] == 0) {
  				return -1;
  			}
  			stacks[p]--;
  			stacks[c]++;
  			if (c == END) {
  				num_active--;
  			}
  		}
  		min_num_active = max(min_num_active, num_active);
  	}

  	if (stacks['q'] != 0 && stacks['u'] != 0 && stacks['a'] != 0 && stacks['c'] != 0) {
  		return -1;
  	}

    return min_num_active;
  }
};
