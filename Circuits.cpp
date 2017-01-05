/*

https://github.com/abhiranjankumar00/TopCoder-SRM-submissions/blob/master/Circuits.cpp

https://community.topcoder.com/stat?c=problem_statement&pm=1593&rd=4494
{"1 2", "2", ""}
{"5 3", "7", ""}
Returns: 12
From above
1)
{"1 2 3 4 5","2 3 4 5","3 4 5","4 5","5",""}
{"2 2 2 2 2","2 2 2 2","2 2 2","2 2","2",""}
Returns: 10
The longest path goes from 0-1-2-3-4-5 for a cost of 10.
2)
{"1","2","3","","5","6","7",""}
{"2","2","2","","3","3","3",""}
Returns: 9
The 0-1-2-3 path costs 6 whereas the 4-5-6-7 path costs 9
3)
{"","2 3 5","4 5","5 6","7","7 8","8 9","10", "10 11 12","11","12","12",""}
{"","3 2 9","2 4","6 9","3","1 2","1 2","5", "5 6 9","2","5","3",""}
Returns: 22
4)
{"","2 3","3 4 5","4 6","5 6","7","5 7",""}
{"","30 50","19 6 40","12 10","35 23","8","11 20",""}
Returns: 105

*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 


class Circuits {
public:
	void dfs_topo(int node, vector<vector<int>>& M, stack<int>& order, set<int>& visited) {
		for (int i = 0; i < int(M.size()); ++i) {
			if (M[node][i] == 0 || visited.count(i) == 1) {
				continue;
			}
			dfs_topo(i, M, order, visited);
		}
		order.push(node);
		visited.insert(node);
	}

	int howLong(vector <string> connects, vector <string> costs) {
		int n = int(connects.size());
		vector<vector<int>> M(n);
		for (int i = 0; i < n; ++i) {
			M[i].reserve(n);
			for (int j = 0; j < n; ++j) {
				M[i][j] = 0;
			}
		}

		for (int i = 0; i < n; ++i) {
			istringstream ia(connects[i]);
			istringstream ib(costs[i]);
			int x, y;
			while (ia >> x && ib >> y) {
				M[i][x] = y;
			}
		}
		// Topological sort.
		stack<int> order;
		set<int> visited;

		for (int i = 0; i < n; ++i) {
			if (visited.count(i) == 1) {
				continue;
			}
			dfs_topo(i, M, order, visited);
		}

		int dist[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (M[i][j] == 0) {
					dist[i][j] = -1;
				} else {
					dist[i][j] = M[i][j];
				}
			}
			dist[i][i] = 0;
		}

		int m = 0;
		while(!order.empty()) {
			int mid = order.top();
			order.pop();

			for (int src = 0; src < n; ++src) {
				if (dist[src][mid] != -1) {
					for (int dest = 0; dest < n; ++dest) {
						if (dist[mid][dest] != -1) {
							dist[src][dest] = max(dist[src][dest], dist[src][mid] + dist[mid][dest]);
							m = max(m, dist[src][dest]);
						}
					}
				}
			}
		}

		return m;
	}
};

int main() {
	Circuits c;
	cout << c.howLong(vector<string>{"1 2", "2", ""}, vector<string>{"5 3", "7", ""}) << " " << 12 << endl;
	cout << c.howLong(vector<string>{"1 2 3 4 5","2 3 4 5","3 4 5","4 5","5",""}, vector<string>{"2 2 2 2 2","2 2 2 2","2 2 2","2 2","2",""}) << " " << 10 << endl;
	cout << c.howLong(vector<string>{"1","2","3","","5","6","7",""}, vector<string>{"2","2","2","","3","3","3",""}) << " " << 9 << endl;
	cout << c.howLong(vector<string>{"","2 3 5","4 5","5 6","7","7 8","8 9","10", "10 11 12","11","12","12",""}, vector<string>{"","3 2 9","2 4","6 9","3","1 2","1 2","5", "5 6 9","2","5","3",""}) << " " << 22 << endl;
	cout << c.howLong(vector<string>{"","2 3","3 4 5","4 6","5 6","7","5 7",""}, vector<string>{"","30 50","19 6 40","12 10","35 23","8","11 20",""}) << " 105" << endl;
}