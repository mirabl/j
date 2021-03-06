/*
https://leetcode.com/problems/find-the-difference/
389. Find the Difference   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 43868
Total Submissions: 86956
Difficulty: Easy
Contributors: Admin
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.

*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char findTheDifference2(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] != t[i]) {
			return t[i];
		}
	}
	return t[t.size() - 1];
}

char findTheDifference3(string s, string t) {
	int freq[26];
	for (int i = 0; i < 26; ++i) {
		freq[i] = 0;
	}
	for (int i = 0; i < (int)s.size(); ++i) {
		freq[(int)(s[i] - 'a')]++;
		freq[(int)(t[i] - 'a')]--;
	}
	freq[(int)(t[t.size() - 1] - 'a')]--;
	for (int i = 0; i < 26; ++i) {
		if (freq[i] < 0) {
			return (char)(i + 'a');
		}
	}
	return (char) 0; // Never reached.
}

char findTheDifference(string s, string t) {
	char c = t[t.size() - 1];
	for (int i = 0; i < (int)s.size(); ++i) {
		c = c ^ s[i];
		c = c ^ t[i];
	}
	return c;
}

int main() {
	cout << findTheDifference("", "a") << " " << "a" << endl;
	cout << findTheDifference("a", "aa") << " " << "a" << endl;
	cout << findTheDifference("aa", "aaa") << " " << "a" << endl;
	cout << findTheDifference("ab", "abc") << " " << "c" << endl;
	cout << findTheDifference("abcd", "abcde") << " " << "e" << endl;
	cout << endl;
}