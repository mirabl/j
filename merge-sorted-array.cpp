/*
https://leetcode.com/problems/merge-sorted-array/
88. Merge Sorted Array   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 136515
Total Submissions: 435891
Difficulty: Easy
Contributors: Admin
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
}

void merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
	int front = m + n - 1;
	int i = m - 1;
	int j = n - 1;
	while (front >= 0) {
		if (i < 0 || (j >= 0 && nums2[j] > nums1[i])) {
			nums1[front] = nums2[j];
			--j;
		} else {
			nums1[front] = nums1[i];
			--i;
		}
		--front;
	}
}

int main() {
	vector<int> v{1, 3, 5, 7, 0, 0, 0};
	merge(v, 4, vector<int>{2, 4, 6}, 3);
	print_vector(v);
	cout << endl;

}