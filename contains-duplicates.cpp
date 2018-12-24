/*
https://leetcode.com/problems/contains-duplicate/
217. Contains Duplicate   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 133215
Total Submissions: 306145
Difficulty: Easy
Contributors: Admin
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
alias a='g++ -Wall -std=c++11 contains_duplicates.cpp && ./a.out'
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(const vector<int>& nums) {
	unordered_set<int> S;
	int n = (int)nums.size();
	for (int i = 0; i < n; ++i) {
		if (S.count(nums[i]) > 0) {
			return true;
		}
		S.insert(nums[i]);
	}
	return false;
}

int main() {
	cout << containsDuplicate(vector<int>{}) << " 0" << endl;
	cout << containsDuplicate(vector<int>{1}) << " 0" << endl;
	cout << containsDuplicate(vector<int>{1, 2}) << " 0" << endl;
	cout << containsDuplicate(vector<int>{1, 2, 3}) << " 0" << endl;
	cout << containsDuplicate(vector<int>{1, 2, 3, 1}) << " 1" << endl;
	cout << containsDuplicate(vector<int>{1, 2, 3, 2}) << " 1" << endl;
	cout << containsDuplicate(vector<int>{1, 2, 3, 3}) << " 1" << endl;
	cout << containsDuplicate(vector<int>{1, 2, 2, 3}) << " 1" << endl;
}
