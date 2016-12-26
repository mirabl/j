/*
78. Subsets   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 132668
Total Submissions: 365256
Difficulty: Medium
Contributors: Admin
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

alias a='g++ -Wall -g subsets.cpp && ./a.out'

*/
#include <iostream>
#include <vector>

using namespace std;

void subsets_rec(vector<int>& nums, vector<int>& subset, int start, vector<vector<int> >& res) {
	res.push_back(subset);
	for (int i = start; i < (int)nums.size(); ++i) {
		subset.push_back(nums[i]);
		subsets_rec(nums, subset, i + 1, res);
		subset.pop_back();
	}
}

vector<vector<int> > subsets(vector<int>& nums) {
	vector<vector<int> > res;
	vector<int> subset;
	subsets_rec(nums, subset, 0, res);
	return res;
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<vector<int> > r = subsets(v);
	for (int i = 0; i < (int)r.size(); ++i) {
		for (int j = 0; j < (int)r[i].size(); ++j) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}


}