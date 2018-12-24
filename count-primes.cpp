/*
https://leetcode.com/problems/count-primes/
204. Count Primes   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 93874
Total Submissions: 360675
Difficulty: Easy
Contributors: Admin
Description:

Count the number of prime numbers less than a non-negative number, n.

alias a='g++ -std=c++11 count_primes.cpp && ./a.out'

*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countPrimes(int n) {
	if (n < 2) {
		return 0;
	}
	int max_fact = sqrt(n);

	vector<bool> is_prime(n, true); // is_prime[i]: is i prime?
	is_prime[1] = false;
	int count = n - 2;
	for (int x = 2; x <= max_fact + 1; ++x) {
		if (!is_prime[x] || (x > 2 && x % 2 == 0) || (x > 3 && x % 3 == 0)) {
			continue;
		}
		int y = x*x;
		while (y < n) {
			if (is_prime[y]) {
				count--;
				is_prime[y] = false;
			}
			y += x;
		}
	}
	return count;
}

int main() {
	cout << countPrimes(1) << " " << 0 << endl;
	cout << countPrimes(2) << " " << 0 << endl;
	cout << countPrimes(3) << " " << 1 << endl;
	cout << countPrimes(4) << " " << 2 << endl;
	cout << countPrimes(5) << " " << 2 << endl;
	cout << countPrimes(6) << " " << 3 << endl;
	cout << countPrimes(19) << " " << 7 << endl;
	cout << countPrimes(10000) << " " << 1229 << endl;
}