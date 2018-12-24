/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
alias a='g++ -g -Wall -std=c++11 longest_substring_without_repeating_chars.cpp && ./a.out'
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool hasNoRepeatedChars(const string& s) {
	unordered_set<char> S;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (S.find(s[i]) != S.end()) {
			return false;
		}
		S.insert(s[i]);
	}
	return true;
}

int lengthLongestSubstringNRPQuadratic(const string& s) {
	int l = 0;
	int n = s.size();

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (hasNoRepeatedChars(s.substr(i, j - i))) {
				if (j - i > l) {
					l = j - i;
				}
			}
		}
	}
	return l;
}

int lengthLongestSubstringNRP(const string& s) {
	int lo = 0;
	int hi = 0;
	int n = s.size();
	int l = 0;

	unordered_set<char> S;

	if (s.empty()) {
		return 0;
	}

	while (hi < n) {
		if (S.find(s[hi]) == S.end()) {
			S.insert(s[hi]);
			hi++;
		} else {
			S.erase(s[lo]);
			lo++;
		}
		if (hi - lo > l) {
			l = hi - lo;
		}
	}
	return l;
}


int main() {
	string s1 = "abcabcab";
	string s2 = "bbbbb";
	string s3 = "pwwzkew";
	string s4 = "c";
	string s5 = "";

	int l1 = lengthLongestSubstringNRP(s1);
	int l2 = lengthLongestSubstringNRP(s2);
	int l3 = lengthLongestSubstringNRP(s3);
	int l4 = lengthLongestSubstringNRP(s4);
	int l5 = lengthLongestSubstringNRP(s5);

	cout << l1 << endl;
	cout << l2 << endl;
	cout << l3 << endl;
	cout << l4 << endl;
	cout << l5 << endl;

	return 0;
}