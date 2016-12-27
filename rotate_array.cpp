/*
https://leetcode.com/problems/rotate-array/
189. Rotate Array   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 104258
Total Submissions: 445957
Difficulty: Easy
Contributors: Admin
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.


alias a='g++ -Wall -g rotate_array.cpp && ./a.out'

*/
#include <iostream>
#include <vector>

using namespace std;

void rotate2(vector<int>& nums, int k) {
    vector<int> B;
    int n = (int)nums.size();
	k = (n + (n - k) % n) % n;
    for (int i = 0; i < n; ++i) {
    	B.push_back(nums[(i + k) % n]);
    }
    nums = B;
}

void rotate3(vector<int>& nums, int k) {
    int n = (int)nums.size();
	k = (n + (n - k) % n) % n;
    for (int j = 0; j < k; ++j) {
    	int old_first = nums[0];
	    for (int i = 0; i < n - 1; ++i) {
	    	nums[i] = nums[i + 1];
	    }
	    nums[n - 1] = old_first;
	}
}

void rotate4(vector<int>& nums, int k) {
    int n = (int)nums.size();
	k = ((n - k) % n + n) % n;
	cout << "k " << k << endl;
    vector<int> save_head;
    for (int i = 0; i < k; ++i) {
    	save_head.push_back(nums[i]);
    }
    for (int i = 0; i < n - k; ++i) {
    	nums[i] = nums[i + k];
    }
    for (int i = 0; i < k; ++i) {
    	nums[n - k + i] = save_head[i];
    }
}

void rotate(vector<int>& nums, int k) {
	int n = (int)nums.size();
	k = ((n - k) % n + n) % n;
	bool visited[n];
	for (int i = 0; i < n; ++i) {
		visited[i] = false;
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i]) {
			continue;
		}
		int save_i = nums[i];
		int j = i;
		while ((j + k) % n != i) {
			int next_j = (j + k) % n;
			nums[j] = nums[next_j];
			visited[j] = true;
			j = next_j;
		}
		nums[j] = save_i;
		visited[j] = true;
	}
}

int main() {
	vector<int> A;
	for (int i = 1; i < 7 + 1; ++i) {
		A.push_back(i);
	}
	int k = 11;
	rotate4(A, k);
	for (int i = 0; i < (int)A.size(); ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
}