/*
https://leetcode.com/problems/climbing-stairs/
70. Climbing Stairs   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 146952
Total Submissions: 380987
Difficulty: Easy
Contributors: Admin
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
	int v0 = 1;
	int v1 = 1;
	for (int i = 2; i < n + 1; ++i) {
		int tmp = v1;
		v1 = v0 + v1;
		v0 = tmp;
	}
	return v1;
}

int main() {
	cout << climbStairs(0) << " 1" << endl;
	cout << climbStairs(1) << " 1" << endl;
	cout << climbStairs(2) << " 2" << endl;
	cout << climbStairs(3) << " 3" << endl;
	cout << climbStairs(4) << " 5" << endl;
}