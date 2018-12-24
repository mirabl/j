/*
https://leetcode.com/problems/factorial-trailing-zeroes/
*/
#include <iostream>

using namespace std;

int trailingZeroes(int n) {
	long long div = 5;
	int x = 0;
	while (div <= n) {
		x += n / div;
		div *= 5;
	}
    return x;
}

int main() {
	cout << trailingZeroes(0) << " 0" << endl;
	cout << trailingZeroes(1) << " 0" << endl;
	cout << trailingZeroes(0) << " 0" << endl;
	cout << trailingZeroes(5) << " 1" << endl;
	cout << trailingZeroes(10) << " 2" << endl;
	cout << trailingZeroes(30) << " 7" << endl;
}