/*
https://leetcode.com/problems/permutations/
46. Permutations   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 136958
Total Submissions: 341165
Difficulty: Medium
Contributors: Admin
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

alias a='g++ -Wall -g permutations.cpp && ./a.out'

*/
#include <iostream>
#include <vector>

using namespace std;

void permute_rec(int start, vector<int>& nums, vector<vector<int> >& res) {
	if (start == (int)nums.size() - 1) {
		res.push_back(nums);
		return;
	}
	for (int i = start; i < (int)nums.size(); ++i) {
		swap(nums[start], nums[i]);
		permute_rec(start + 1, nums, res);
		swap(nums[start], nums[i]);
	}
}

vector<vector<int> > permute(vector<int>& nums) {
	vector<vector<int> > r;
	vector<int> empty;
	permute_rec(0, nums, r);
	return r;
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<vector<int> > r;
	r = permute(v);
	for (int i = 0; i < (int)r.size(); ++i) {
		for (int j = 0; j < (int)r[i].size(); ++j) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
}

class Solution {
public:
    void r(vector<int>& nums, int offset, vector<vector<int>>& res) {
        int n = nums.size();
        
        if (offset == n) {
            res.push_back(nums);
            return;
        }
        
        for (int i = offset; i < n; i++) {
            swap(nums[i], nums[offset]);
            r(nums, offset + 1, res);
            swap(nums[i], nums[offset]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        r(nums, 0, res);
        return res;
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> res;
    void r(vector<int>& nums, int offset) {
        if (offset == n) {
            res.push_back(nums);
            return;
        }
        
        for (int i = offset; i < n; i++) {
            swap(nums[i], nums[offset]);
            r(nums, offset + 1);
            swap(nums[i], nums[offset]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        r(nums, 0);
        return res;
    }
};
