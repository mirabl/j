/*
https://leetcode.com/problems/pascals-triangle-ii/
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
	rowIndex++;
	vector<int> res(rowIndex, 0);
	if (rowIndex == 0) { 
		return res;
	}
	res[0] = 1;
	for (int i = 1; i < rowIndex; ++i) {
		for (int j = rowIndex - 1; j > 0; --j) {
			res[j] = res[j] + res[j - 1];
		}
	}
	return res;
}

int main() {
	vector<int> r = getRow(0);
	for (int i = 0; i < (int)r.size(); ++i) {
		cout << r[i] << " ";
	}
	cout << endl;
}
