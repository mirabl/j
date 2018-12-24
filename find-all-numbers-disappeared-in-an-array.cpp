/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

448. Find All Numbers Disappeared in an Array   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 13243
Total Submissions: 23014
Difficulty: Easy
Contributors: yuhaowang001
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
alias a='co find_all_numbers_disappeared_in_an_array.cpp && ./a.out'
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print_vector(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
}

vector<int> findDisappearedNumbers(const vector<int>& nums) {
	vector<int> v;
	set<int> S;
	for (int i = 0; i < (int)nums.size(); ++i) {
		S.insert(nums[i]);
	}
	for (int i = 1; i <= (int)nums.size(); ++i) {
		if (S.count(i) == 0) {
			v.push_back(i);
		}
	}
	return v;
}

/** trick to do it without memory: 
https://discuss.leetcode.com/topic/65738/java-accepted-simple-solution
*/

int main() {
	print_vector(findDisappearedNumbers(vector<int>{4,3,2,7,8,2,3,1}));
	cout << " ";
	print_vector(vector<int>{5, 6});
	cout << endl;
}