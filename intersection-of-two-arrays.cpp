/*
https://leetcode.com/problems/intersection-of-two-arrays/
349. Intersection of Two Arrays   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 65831
Total Submissions: 144594
Difficulty: Easy
Contributors: Admin
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
}

vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
	set<int> S(nums1.begin(), nums1.end());
	vector<int> res;
	for (int i = 0; i < (int)nums2.size(); ++i) {
		if (S.count(nums2[i]) != 0) {
			res.push_back(nums2[i]);
			S.erase(nums2[i]);
		}
	}
	return res;
}

int main() {
	print_vector(intersection(vector<int>{1, 2, 2, 1}, vector<int>{2, 2}));
	cout << " ";
	cout << "[2]" << endl;
}