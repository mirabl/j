/*
https://leetcode.com/problems/reverse-integer/
alias a='g++ reverse_integer.cpp -Wall && ./a.out'

*/
#include <iostream>

using namespace std;

int reverse_integer(int x) {
	int y = 0;

	bool negative = (x < 0);
	if (negative) {
		x = -x;
	}

	while (x != 0) {
		y = y * 10 + (x % 10);
		x = x / 10;
	}

	if (negative) {
		y = -y;
	}

	return y;
}

int main() {
	cout << reverse_integer(100) << endl;
	cout << reverse_integer(-123) << endl;
	cout << reverse_integer(0) << endl;
	return 0;
}