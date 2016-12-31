/*
https://leetcode.com/problems/isomorphic-strings/
205. Isomorphic Strings   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 86928
Total Submissions: 268319
Difficulty: Easy
Contributors: Admin
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t) {
	map<char, char> f;
	map<char, char> g;

	for (int i = 0; i < (int)s.size(); ++i) {
		char x = s[i];
		char y = t[i];
		if ((f.count(x) != 0 && f[x] != y)
			|| (g.count(y) != 0 && g[y] != x)) {
			return false;
		}
		f[x] = y;
		g[y] = x;
	}
	return true;
}

int main() {
	cout << isIsomorphic("", "") << " 1" << endl;
	cout << isIsomorphic("a", "a") << " 1" << endl;
	cout << isIsomorphic("ab", "ab") << " 1" << endl;
	cout << isIsomorphic("ab", "cd") << " 1" << endl;
	cout << isIsomorphic("aba", "cda") << " 0" << endl;
	cout << isIsomorphic("aba", "cdc") << " 1" << endl;
	cout << isIsomorphic("beeb", "arra") << " 1" << endl;
	cout << isIsomorphic("0118", "8559") << " 1" << endl;
	cout << isIsomorphic("paper", "title") << " 1" << endl;
	cout << isIsomorphic("foo", "bar") << " 0" << endl;
	cout << isIsomorphic("egg", "add") << " 1" << endl;
	cout << endl;
}
