/*
https://leetcode.com/problems/power-of-two/

231. Power of Two   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 114138
Total Submissions: 291548
Difficulty: Easy
Contributors: Admin
Given an integer, write a function to determine if it is a power of two.

alias a='g++ -Wall -std=c++11 power_of_two.cpp && ./a.out'
*/
#include <iostream>

using namespace std;

bool isPowerOfTwo2(int n) {
	if (n <= 0) {
		return 0;
	}
	while (n != 1) {
		if (n % 2 != 0) {
			return false;
		}
		n = n / 2;
	}
	return true;
}

bool isPowerOfTwo(int x) {
	if (x <= 0) {
		return false;
	}
	return x == (x & ~(x - 1));
}

int main() {
	cout << isPowerOfTwo(0) << " 0" << endl;
	cout << isPowerOfTwo(1) << " 1" << endl;
	cout << isPowerOfTwo(2) << " 1" << endl;
	cout << isPowerOfTwo(3) << " 0" << endl;
	cout << isPowerOfTwo(4) << " 1" << endl;
	cout << isPowerOfTwo(5) << " 0" << endl;
	cout << isPowerOfTwo(-1) << " 0" << endl;
	cout << isPowerOfTwo(-2) << " 0" << endl;
}