/*
https://leetcode.com/problems/hamming-distance/

*/
#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {

	int z = x ^ y;
	int w = 0;
	for (int i = 0; i < 31; ++i) {
		if (((z >> i) & 1) == 1) {
			w++;
		}
	}
	return w;
}


int main() {
	cout << hammingDistance(1, 4) << endl;
	return 0;
}