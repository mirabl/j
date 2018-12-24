/*
https://leetcode.com/problems/nth-digit/
400. Nth Digit   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 12594
Total Submissions: 41272
Difficulty: Easy
Contributors: Admin
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/
#include <iostream>
#include <cmath>

using namespace std;

int findNthDigit(int n) {
	int d = 1;
	long long c = 9;
	long long base = 9;
	while (n > c) {
		++d;
		base = base * 10;
		c += d * base;
	}
	c = 1 + c - d * base;
	int digits_in_block = d;
	int digit_offset_in_block = n - c;
	int x = pow(10, d - 1) + digit_offset_in_block / digits_in_block;
	int m = digits_in_block - 1 - (digit_offset_in_block % digits_in_block);
	for (int i = 0; i < m; ++i) {
		x = x / 10;
	}
	return x % 10;
}

int main() {
	// cout << findNthDigit(1) << " 1" << endl;
	// cout << findNthDigit(2) << " 2" << endl;
	// cout << findNthDigit(3) << " 3" << endl;
	// cout << findNthDigit(9) << " 9" << endl;
	// cout << findNthDigit(10) << " 1" << endl;
	// cout << findNthDigit(11) << " 0" << endl;
	// cout << findNthDigit(12) << " 1" << endl;
	// cout << findNthDigit(12) << " 1" << endl;
	// cout << findNthDigit(13) << " 1" << endl;
	// cout << findNthDigit(14) << " 2" << endl;
	cout << findNthDigit(190) << " 1" << endl;
	cout << findNthDigit(191) << " 0" << endl;
	cout << findNthDigit(192) << " 0" << endl;
	cout << findNthDigit(193) << " 1" << endl;
	cout << findNthDigit(194) << " 0" << endl;
	cout << findNthDigit(195) << " 1" << endl;
	cout << findNthDigit(1000000000) << " ?" << endl;
	cout << "---" << endl;


	// for (int i = 0; i < 200; ++i) {
	// 	cout << i << ":" << findNthDigit(i) << endl;
	// }
}