/*
https://leetcode.com/problems/reverse-string/
344. Reverse String   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 117661
Total Submissions: 204674
Difficulty: Easy
Contributors: Admin
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
alias a='g++ -Wall reverse_string.cpp && ./a.out'
*/
#include <iostream>
#include <string>

using namespace std;

string reverseString(const string& s) {
	int n = (int)s.size();
	string t;
	t.resize(n);
	for (int i = n - 1; i >= 0; --i) {
		t[n - 1 - i] = s[i];
	}
	return t;
}

int main() {
	cout << "'" << reverseString("") << "' ''" << endl;
	cout << reverseString("a") << " a" << endl;
	cout << reverseString("ab") << " ba" << endl;
	cout << reverseString("abc") << " cba" << endl;
	cout << reverseString("hello") << " olleh" << endl;
}