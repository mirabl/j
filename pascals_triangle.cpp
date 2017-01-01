/*
https://leetcode.com/problems/pascals-triangle/
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	if (numRows == 0) {
		return res;
	}
	vector<int> row1;
	row1.push_back(1);
	res.push_back(row1);

	for (int i = 1; i < numRows; ++i) {
		vector<int> r;
		r.push_back(1);
		int k = res.size() - 1;
		for (int j = 0; j < (int)res[k].size() - 1; ++j) {
			r.push_back(res[k][j] + res[k][j + 1]);
		}
		r.push_back(1);
		res.push_back(r);
	}
	return res;
}

int main() {
	vector<vector<int>> r = generate(5);
	for (int i = 0; i < (int)r.size(); ++i) {
		for (int j = 0; j < (int)r[i].size(); ++j) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}

}
