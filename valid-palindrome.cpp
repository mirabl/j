/*
https://leetcode.com/problems/valid-palindrome/
125. Valid Palindrome   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 134605
Total Submissions: 533557
Difficulty: Easy
Contributors: Admin
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

alias a='g++ -Wall -g valid_palindrome.cpp && ./a.out'
*/
#include <iostream>
#include <string>

using namespace std;

bool isPalindromeRec(string s) {
	if (s.empty()) {
		return true;
	}
	int n = (int)s.size();
	if (!isalnum(s[0])) {
		return isPalindromeRec(s.substr(1));
	} else if(!isalnum(s[n - 1])) {
		return isPalindromeRec(s.substr(0, n - 1));
	} else {
		return ((tolower(s[0]) == tolower(s[n - 1])) && isPalindromeRec(s.substr(1, n - 2)));
	}
}

bool isPalindrome(string s) {
	if (s.empty()) {
		return true;
	}
	int n = (int)s.size();
	int lo = 0;
	int hi = n - 1;
	while (lo < hi) {
		if (!isalnum(s[lo])) {
			++lo;
		} else if (!isalnum(s[hi])) {
			--hi;
		} else {
			if (tolower(s[lo]) != tolower(s[hi])) {
				return false;
			} 
			++lo;
			--hi;
		}
	}
	return true;
}

int main() {
	string s("A man, a plan, a canal: Panama");
	string t("race a car");

	cout << isPalindrome(s) << endl;
	cout << isPalindrome(t) << endl;
	cout << isPalindrome(".;") << endl;
	cout << isPalindrome("") << endl;
	cout << isPalindrome("aa") << endl;
}