/*
https://leetcode.com/problems/power-of-four/
342. Power of Four   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 49097
Total Submissions: 131747
Difficulty: Easy
Contributors: Admin
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

alias a='g++ -Wall -std=c++11 power_of_four.cpp && ./a.out'
*/
#include <iostream>

using namespace std;

bool isPowerOfFour(int num) {
	if (num <= 0) {
		return false;
	}

	while (num != 1) {
		if (num % 4 != 0) {
			return false;
		}
		num = num / 4;
	}	
	return true;
}


int main() {
	cout << isPowerOfFour(0) << " false" << endl;
	cout << isPowerOfFour(1) << " false" << endl;
	cout << isPowerOfFour(4) << " true" << endl;
	cout << isPowerOfFour(-4) << " true" << endl;
	cout << isPowerOfFour(16) << " true" << endl;
	cout << isPowerOfFour(-16) << " true" << endl;
	cout << isPowerOfFour(64) << " true" << endl;
	cout << isPowerOfFour(5) << " false" << endl;
	cout << isPowerOfFour(53) << " false" << endl;
	cout << isPowerOfFour(1<<30) << " true" << endl;
}