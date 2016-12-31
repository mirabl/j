/*
https://leetcode.com/problems/length-of-last-word/
58. Length of Last Word   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 123788
Total Submissions: 399071
Difficulty: Easy
Contributors: Admin
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
	int i = (int)s.size() - 1;
	// skip whitespace
	while (i >= 0 && s[i] == ' ') {
		--i;
	}
	if (i < 0) {
		return 0;
	}
	// get word len
	int len = 0;
	while (i >= 0 && s[i] != ' ') {
		--i;
		++len;
	}
	return len;
}

int main() {
	cout << lengthOfLastWord("") << " 0" << endl;
	cout << lengthOfLastWord(" ") << " 0" << endl;
	cout << lengthOfLastWord("  ") << " 0" << endl;
	cout << lengthOfLastWord("a") << " 1" << endl;
	cout << lengthOfLastWord(" a") << " 1" << endl;
	cout << lengthOfLastWord(" a ") << " 1" << endl;
	cout << lengthOfLastWord(" ab ") << " 1" << endl;
	cout << lengthOfLastWord(" ab ") << " 2" << endl;
	cout << lengthOfLastWord(" cze ab ") << " 2" << endl;
	cout << lengthOfLastWord("Hello World") << " 5" << endl;
}