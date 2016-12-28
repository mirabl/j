/*
https://leetcode.com/problems/single-number/
136. Single Number   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 181591
Total Submissions: 344958
Difficulty: Easy
Contributors: Admin
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
alias a='g++ -Wall single_number.cpp -std=c++11 && ./a.out'
*/
#include <iostream>
#include <vector>

using namespace std;

int singleNumber(const vector<int>& nums) {
	int x = 0;
	for (int i = 0; i < (int)nums.size(); ++i) {
		x = x ^ nums[i];
	}
	return x;
}

int main() {
	cout << singleNumber(vector<int>{1, 1, 2}) << " 2" << endl;
	cout << singleNumber(vector<int>{2, 1, 1}) << " 2" << endl;
	cout << singleNumber(vector<int>{1, 2, 1}) << " 2" << endl;
	cout << singleNumber(vector<int>{1, 2, 1, 3, 2}) << " 3" << endl;
	cout << singleNumber(vector<int>{1, 2, 1, 2, 3}) << " 3" << endl;
}