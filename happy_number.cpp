/*

https://leetcode.com/problems/happy-number/
202. Happy Number   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 102114
Total Submissions: 261269
Difficulty: Easy
Contributors: Admin
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

alias a='g++ -Wall -std=c++11 happy_number.cpp && ./a.out'
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int reduce(int n) {
	int s = 0;
	while (n != 0) {
		int d = n % 10;
		s += d * d;
		n = n / 10;
	}
	return s;
}

bool isHappy2(int n) {
	unordered_set<int> S;
	while (true) {
		if (n == 1) {
			return true;
		}
		if (S.count(n) != 0) {
			return false;
		}
		S.insert(n);
		n = reduce(n);
	}
}

bool isHappy(int n) {
	int slow = n;
	int fast = n;
	do {
		fast = reduce(reduce(fast));
		slow = reduce(slow);
	} while (slow != fast);
	if (slow == 1) {
		return true;
	}
	return false;
}

int main() {
	cout << isHappy(0) << " 0" << endl;
	cout << isHappy(1) << " 1" << endl;
	cout << isHappy(2) << " 0" << endl;
	cout << isHappy(19) << " 1" << endl;
}