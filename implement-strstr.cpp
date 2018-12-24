/*
https://leetcode.com/problems/implement-strstr/
28. Implement strStr()   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 148060
Total Submissions: 552085
Difficulty: Easy
Contributors: Admin
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
alias a='g++ -Wall -g -std=c++11 implement_strstr.cpp && ./a.out'

*/
#include <iostream>
#include <string>

using namespace std;

int strStr(string s, string t) {
	int n = (int)s.size();
	int m = (int)t.size();

	if (t.empty()) {
		return 0;
	}

	for (int i = 0; i < n - m + 1; ++i) {
		int j = i;
		int k = 0;
		for (; k < m; ++k) {
			if (s[j] == t[k]) {
				++j;
			} else {
				break;
			}
		}
		if (k == m) {
			return i;
		}
	}
	return -1;
}

int main() {
	cout << strStr("abcde", "a") << " 0" << endl;
	cout << strStr("abcde", "ab") << " 0" << endl;
	cout << strStr("abcde", "abcd") << " 0" << endl;
	cout << strStr("abcde", "abcde") << " 0" << endl;
	cout << strStr("abcde", "b") << " 1" << endl;
	cout << strStr("abcde", "bcde") << " 1" << endl;
	cout << strStr("abcde", "e") << " 4" << endl;
	cout << strStr("abcde", "z") << " -1" << endl;
	cout << strStr("abcde", "abcdef") << " -1" << endl;
	cout << strStr("abcdeab", "ab") << " 0" << endl;
	cout << strStr("abcdeab0", "ab0") << " 5" << endl;
}