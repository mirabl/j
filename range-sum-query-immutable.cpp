/*
https://leetcode.com/problems/range-sum-query-immutable/
303. Range Sum Query - Immutable   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 53717
Total Submissions: 205520
Difficulty: Easy
Contributors: Admin
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

alias a='g++ -Wall -std=c++11 range_sum_query_immutable.cpp && ./a.out'
*/
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	vector<int> accu;
    NumArray(vector<int> &nums) {
    	int s = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
        	accu.push_back(s);
        	s += nums[i];
        }
    	accu.push_back(s);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
};

int main() {
	vector<int> nums = {-2, 0, 3, -5, 2, -1};
// Your NumArray object will be instantiated and called as such:
NumArray numArray(nums);
cout << numArray.sumRange(0, 2) << " 1" << endl;
cout << numArray.sumRange(2, 5) << " -1" << endl;
cout << numArray.sumRange(0, 5) << " -3" << endl;
}