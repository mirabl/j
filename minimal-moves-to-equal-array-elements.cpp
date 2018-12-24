/*
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
453. Minimum Moves to Equal Array Elements   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 10970
Total Submissions: 23849
Difficulty: Easy
Contributors: amehrotra2610
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int minMoves(const vector<int>& nums) {
	if (nums.size() == 1) {
		return 0;
	}

	int min_e = *min_element(nums.begin(), nums.end());
	int sum = 0;
	for (int n : nums) {
		sum += n;
	}
	return sum - (int)nums.size() * min_e;
}

int main() {
	cout << minMoves(vector<int>{1, 1}) << " 0" << endl;
	cout << minMoves(vector<int>{1, 2}) << " 1" << endl;
	cout << minMoves(vector<int>{1, 2, 3}) << " 3" << endl;
}