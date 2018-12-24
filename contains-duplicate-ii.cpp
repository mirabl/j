/*
https://leetcode.com/problems/contains-duplicate-ii/
219. Contains Duplicate II   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 89803
Total Submissions: 286101
Difficulty: Easy
Contributors: Admin
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsNearbyDuplicate(const vector<int>& nums, int k) {
	set<int> previous;
	if (k == 0) {
		return false;
	}
	for (int i = 0; i < (int)nums.size(); ++i) {
		if (previous.count(nums[i]) != 0) {
			return true;
		}
		if (i >= k) {
			previous.erase(nums[i - k]);
		}
		previous.insert(nums[i]);
	}
	return false;
}

int main() {
	cout << containsNearbyDuplicate(vector<int>{}, 0) << " 0" << endl;
	cout << containsNearbyDuplicate(vector<int>{}, 5) << " 0" << endl;
	cout << containsNearbyDuplicate(vector<int>{1}, 0) << " 0" << endl;
	cout << containsNearbyDuplicate(vector<int>{1, 2}, 1) << " 0" << endl;
	cout << containsNearbyDuplicate(vector<int>{1, 1}, 1) << " 1" << endl;
	cout << containsNearbyDuplicate(vector<int>{1, 1, 2}, 1) << " 1" << endl;
	cout << containsNearbyDuplicate(vector<int>{1, 2, 2}, 1) << " 1" << endl;
	cout << containsNearbyDuplicate(vector<int>{1, 2, 1}, 1) << " 0" << endl;
	cout << containsNearbyDuplicate(vector<int>{1, 2, 1}, 2) << " 1" << endl;
	cout << endl;
}