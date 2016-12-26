/*

https://leetcode.com/problems/total-hamming-distance/

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.

alias a='g++ total_hamming_distance.cpp -Wall && ./a.out '

*/
#include <iostream>
#include <vector>
using namespace std;

// Too long. Quadratic.
int totalHammingDistanceBF(vector<int>& nums) {
	int w = 0;
	for (int i = 0; i < (int)nums.size(); ++i) {
		for (int j = i + 1; j < (int)nums.size(); ++j) {
			for (int k = 0; k < 31; ++k) {
				int z = nums[i] ^ nums[j];
				w += ((z >> k) & 1);
			}
		}
	}
	return w;
}

int totalHammingDistance(vector<int>& nums) {
	int counts[31];
	for (int i = 0; i < 31; ++i) {
		counts[i] = 0;
	}
	for (int i = 0; i < (int)nums.size(); ++i) {
		for (int j = 0; j < 31; ++j) {
			counts[j] += (nums[i] >> j) & 1;
		}
	}
	int w = 0;
	int n = (int)nums.size();
	for (int i = 0; i < 31; ++i) {
		w += counts[i] * (n - counts[i]);
	}
	return w;
}

int main() {
	vector<int> A;
	A.push_back(4);
	A.push_back(14);
	A.push_back(2);

	cout << totalHammingDistance(A) << endl;
}