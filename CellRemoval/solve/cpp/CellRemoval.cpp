#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class CellRemoval {
public:
  void delete_rec(int deletedCell, map<int, vector<int>>& children, set<int>& deleted) {
  	deleted.insert(deletedCell);
  	for (int child: children[deletedCell]) {
  		delete_rec(child, children, deleted);
  	}
  }

  int cellsLeft(vector<int> const &parent,
                int deletedCell) {
  	map<int, vector<int>> children;
  	int N = int(parent.size());
  	for (int i = 0; i < N; i++) {
  		children[parent[i]].push_back(i);
  	}
  	set<int> deleted;
  	int count = 0;
  	delete_rec(deletedCell, children, deleted);
  	for (int i = 0; i < N; i++) {
  		if (children[i].empty() && deleted.count(i) == 0) {
  			count++;
  		}
  	}
    return count;
  }
};
