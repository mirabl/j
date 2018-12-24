/*
https://leetcode.com/problems/longest-palindrome/
409. Longest Palindrome   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 20898
Total Submissions: 47197
Difficulty: Easy
Contributors: Admin
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
alias a='g++ -Wall -std=c++11 longest_palindrome.cpp && ./a.out'
*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int longestPalindrome2(string s) {
	unordered_map<char, int> M;
	for (int i = 0; i < (int)s.size(); ++i) {
		++M[s[i]];
	}

	int len = 0;
	bool single = false;
	for (unordered_map<char, int>::iterator it = M.begin(); it != M.end(); ++it) {
		int f = it->second;
		if (f > 1) {
			len += f - (f % 2);
			f = f % 2;
		}
		if (f == 1 && !single) {
			single = true;
		}
	}
	if (single) {
		++len;
	}

	return len;
}

int longestPalindrome3(string s) {
	unordered_set<char> S;
	int len = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		char c = s[i];
		if (S.count(c) == 0) {
			S.insert(c);
		} else {
			len += 2;
			S.erase(c);
		}
	}

	if (!S.empty()) {
		++len;
	}
	return len;
}

int longestPalindrome(string s) {
	int S[256] = { 0 };
	int single_count = 0;
	int len = 0;
	int n = (int)s.size();
	for (int i = 0; i < n; ++i) {
		int c = (int)s[i];
		if (S[c] == 0) {
			S[c] = 1;
			++single_count;
		} else {
			len += 2;
			S[c] = 0;
			--single_count;
		}
	}

	if (single_count > 0) {
		++len;
	}
	return len;
}


int main() {
	cout << longestPalindrome("") << " 0" << endl;
	cout << longestPalindrome("a") << " 1" << endl;
	cout << longestPalindrome("aa") << " 2" << endl;
	cout << longestPalindrome("aaa") << " 3" << endl;
	cout << longestPalindrome("ab") << " 1" << endl;
	cout << longestPalindrome("abb") << " 3" << endl;
	cout << longestPalindrome("baabc") << " 5" << endl;
}