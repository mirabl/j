/*
https://leetcode.com/problems/third-maximum-number/
414. Third Maximum Number   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 14204
Total Submissions: 53305
Difficulty: Easy
Contributors: ZengRed , 1337c0d3r
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

alias a='g++ -Wall -std=c++11 -g third_maximum_number.cpp && ./a.out'
*/
#include <iostream>
#include <vector>

using namespace std;

int thirdMax(vector<int>& nums) {
	int n = (int)nums.size();
	vector<int> maxima;	// maxima[i] is the (i+1)-th max of the array

	for (int i = 0; i < n; ++i) {
		int v = nums[i];
		int n_max = (int)maxima.size();

		if (n_max == 0 || v > maxima[0]) {
			maxima.insert(maxima.begin() + 0, v);
		} else if (v != maxima[0] && (n_max == 1 || v > maxima[1])) {
			maxima.insert(maxima.begin() + 1, v);
		} else if (v != maxima[0] && v != maxima[1] && (n_max == 2 || v > maxima[2])) {
			maxima.insert(maxima.begin() + 2, v);
		}

		if ((int)maxima.size() > 3) {
			maxima.resize(3);
		}
	}
	if ((int)maxima.size() == 3) {
		return maxima[2];
	} else {
		return maxima[0];
	}
}

int main() {
	vector<int> v1 = {3, 2, 1};
	cout << thirdMax(v1) << endl; // 1

	vector<int> v2 = {1, 2};
	cout << thirdMax(v2) << endl; // 2

	vector<int> v3 = {2, 2, 3, 1};
	cout << thirdMax(v3) << endl; // 1

	vector<int> v4 = {1};
	cout << thirdMax(v4) << endl; // 1

	vector<int> v5 = {1, 1, 1};
	cout << thirdMax(v5) << endl; // 1

	vector<int> v6 = {3, 2, 4, 1}; // 2
	cout << thirdMax(v6) << endl;

	vector<int> v7 = {1, 2, 3, 4}; // 2
	cout << thirdMax(v7) << endl;


}