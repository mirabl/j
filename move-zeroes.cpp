/*
https://leetcode.com/problems/move-zeroes/
283. Move Zeroes   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 144891
Total Submissions: 304338
Difficulty: Easy
Contributors: Admin
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
} 

void moveZeroes2(vector<int>& nums) {
	int n = (int)nums.size();
	int i = 0;
	int num_zeroes = 0;
	while (i < n - num_zeroes) {
		if (nums[i] == 0) {
			for (int j = i; j < n - 1; ++j) {
				nums[j] = nums[j + 1];
			}
			nums[n - 1] = 0;
			num_zeroes++;
		} else {
			i += 1;
		}
	}
}

void moveZeroes(vector<int>& nums) {
	int n = (int)nums.size();
	int front = 0;
	int back = 0;
	while (front < n) {
		if (nums[front] != 0) {
			nums[back] = nums[front];
			++back;
		}
		++front;
	}
	while (back < n) {
		nums[back] = 0;
		++back;
	}
}

int main() {
	vector<int> v{0, 1, 0, 3, 12};
	moveZeroes(v);
	print_vector(v);
	cout << " / ";
	print_vector(vector<int>{1, 3, 12, 0, 0});
	cout << endl;
}