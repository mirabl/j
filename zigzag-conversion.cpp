/*

https://leetcode.com/problems/zigzag-conversion/

alias a='g++ zigzag_conversion.cpp -Wall && ./a.out'

*/

#include <iostream>
#include <string>

using namespace std;

string convert(const string& s, int n) {
	string res;

	if (n == 1) {
		return s;
	}

	int l = s.size();
	int p = 2 * (n - 1);
	int i = 0;
	while (i < l) {
		res.push_back(s[i]);
		i += p;
	}
	for (int j = 1; j < n - 1; ++j) {
		i = 0;
		while ((i + j) < l) {
			res.push_back(s[i+j]);
			if (i + p - j < l) {
				res.push_back(s[i + p - j]);
			}
			i += p;
		}
	}
	i = n - 1;
	while (i < l) {
		res.push_back(s[i]);
		i += p;
	}

	return res;
}

int main() {
	cout << convert("0123456789", 5) << endl;
}