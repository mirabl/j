/*
https://leetcode.com/problems/repeated-substring-pattern/
459. Repeated Substring Pattern   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 11002
Total Submissions: 27810
Difficulty: Easy
Contributors: YuhanXu
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
alias a='g++ -Wall -std=c++11 repeated_substring_pattern.cpp && ./a.out'
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool repeatedSubstringPattern(const string& str) {
	int n = (int)str.size();
	for (int l = 1; l < (n / 2) + 1; ++l) {
		if (n % l != 0) {
			continue;
		}
		int i = 0;
		for (; i < l; ++i) {
			int k = i;
			while (k < (n - l)) {
				if (str[k] != str[k + l]) {
					break;
				}
				k += l;
			}
			if (k < n -l) {
				break;
			}
		}
		if (i == l) {
			return true;
		}
	}
	return false;
}

int main() {
	cout << repeatedSubstringPattern("a") << " 0" << endl;
	cout << repeatedSubstringPattern("aa") << " 1" << endl;
	cout << repeatedSubstringPattern("aaa") << " 1" << endl;
	cout << repeatedSubstringPattern("ab") << " 0" << endl;
	cout << repeatedSubstringPattern("abab") << " 1" << endl;
	cout << repeatedSubstringPattern("aba") << " 0" << endl;
	cout << repeatedSubstringPattern("abcabcabcabc") << " 1" << endl;
	cout << repeatedSubstringPattern("aabaaba") << " 0" << endl;

}