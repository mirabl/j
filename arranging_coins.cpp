/*
https://leetcode.com/problems/arranging-coins/
441. Arranging Coins   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 11330
Total Submissions: 31308
Difficulty: Easy
Contributors: Admin
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/
#include <iostream>

using namespace std;

int arrangeCoins(int n) {
	int levels = 0;
	while (n >= 0) {
		levels++;
		n = n - levels;
	}
	return levels - 1;
}

int main() {
	cout << arrangeCoins(1) << " 1" << endl;
	cout << arrangeCoins(2) << " 1" << endl;
	cout << arrangeCoins(3) << " 2" << endl;
	cout << arrangeCoins(4) << " 2" << endl;
	cout << arrangeCoins(5) << " 2" << endl;
	cout << arrangeCoins(6) << " 3" << endl;
	cout << arrangeCoins(8) << " 3" << endl;
}