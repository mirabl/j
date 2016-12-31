/*
https://leetcode.com/problems/valid-parentheses/
20. Valid Parentheses   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 158010
Total Submissions: 494040
Difficulty: Easy
Contributors: Admin
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s) {
	stack<char> S;
	map<char, char> closing;
	closing['{'] = '}';
	closing['['] = ']';
	closing['('] = ')';

	for (int i = 0; i < (int)s.size(); ++i) {
		char c = s[i];
		if (c == '(' || c == '[' || c == '{') {
			S.push(closing[c]);
		} else {
			if (S.empty() || S.top() != c) {
				return false;
			} else {
				S.pop();
			}
		}
	}
	return S.empty();
}

int main() {
	cout << isValid("") << " 1" << endl;
	cout << isValid("(") << " 0" << endl;
	cout << isValid(")") << " 0" << endl;
	cout << isValid("((") << " 0" << endl;
	cout << isValid(")(") << " 0" << endl;
	cout << isValid("()") << " 1" << endl;
	cout << isValid("[()]") << " 1" << endl;
	cout << isValid("[({})]") << " 1" << endl;
	cout << isValid("()[]{}" ) << " 1" << endl;
	cout << isValid("(]" ) << " 0" << endl;
	cout << isValid("([)]") << " 0" << endl;
}