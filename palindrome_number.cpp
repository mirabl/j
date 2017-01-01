/*
https://leetcode.com/problems/palindrome-number/
*/
#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	} else if (x == 0) {
		return true;
	}

	int y = x;
	int div_hi = 1;
	while (y >= 10) {
		y = y / 10;
		div_hi *= 10;
	}

	int r = 1;
	while (r*r < div_hi) {
		y = (x / (div_hi / r)) % 10;
		int z = (x / r) % 10;
		if (y != z) {
			return false;
		}
		r *= 10;
	}

	return true;
}

int main() {
	cout << isPalindrome(0) << " 1" << endl;
	cout << isPalindrome(1) << " 1" << endl;
	cout << isPalindrome(8) << " 1" << endl;
	cout << isPalindrome(10) << " 0" << endl;
	cout << isPalindrome(11) << " 1" << endl;
	cout << isPalindrome(88) << " 1" << endl;
	cout << isPalindrome(101) << " 1" << endl;
	cout << isPalindrome(56788765) << " 1" << endl;
	cout << endl;
}
