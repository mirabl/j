/*
https://leetcode.com/problems/arithmetic-slices/
413. Arithmetic Slices   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 9507
Total Submissions: 17522
Difficulty: Medium
Contributors: XiangyuLi926
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
alias a='g++ -Wall -std=c++11 arithmetic_slices.cpp && ./a.out'
*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int numberOfArithmeticSlices(const vector<int>& A) {
	int n = (int)A.size();
	if (n < 3) {
		return 0;
	}

	int total_num = 0;
	int current_slice_count = 0;
	for (int i = 2; i < n; ++i) {
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
			// Number of subsequences ending at this position:
			// = number of ss ending at last position + 1
			current_slice_count++;
			total_num += current_slice_count;
		} else {
			current_slice_count = 0;
		}
	}
	return total_num;
}

int main() {

	vector<int> v1 = {1, 2, 3, 4, 6};
	cout << numberOfArithmeticSlices(v1) << endl;
	cout << numberOfArithmeticSlices(vector<int>{}) << endl;
	cout << numberOfArithmeticSlices(vector<int>{1}) << endl;
	cout << numberOfArithmeticSlices(vector<int>{1, 2}) << endl;
	cout << numberOfArithmeticSlices(vector<int>{0, 1, 2, 3, 5, 7, 10}) << " " << 4 << endl;
	cout << numberOfArithmeticSlices(vector<int>{0, 1, 2, 3, 5, 7, 10, 13}) << " " << 5 << endl;
	cout << numberOfArithmeticSlices(vector<int>{0, 1, 2, 3, 5, 7, 10, 13, 16}) << " " << 7 << endl;

}