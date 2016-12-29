/*
https://leetcode.com/problems/number-of-1-bits/

alias a='g++ -Wall number_of_1_bits.cpp && ./a.out'

*/

int hammingWeight(uint32_t n) {
	int w = 0;
	for (int i = 0; i < 32; ++i) {
		if (((n >> i) & 1) == 1) {
			w++;
		}
	}
	return w;
}