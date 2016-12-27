/*
https://leetcode.com/problems/number-of-segments-in-a-string/
434. Number of Segments in a String   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 5438
Total Submissions: 14168
Difficulty: Easy
Contributors: love_FDU_llp
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5

alias a='g++ -Wall -std=c++11 number_of_segments_in_a_string.cpp && ./a.out'
*/
#include <iostream>
#include <string>

using namespace std;

int countSegments2(string s) {
	s = " " + s + " ";
	int n = (int)s.size();
	int num = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == ' ' && s[i + 1] != ' ') {
			num++;
		}
	}
	return num;
}

int countSegments(string s) {
	int n = (int)s.size();
	int num = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) { // !.
			num++;
		}
	}
	return num;
}

int main() {
	cout << countSegments("") << " 0" << endl;
	cout << countSegments(" ") << " 0" << endl;
	cout << countSegments("   ") << " 0" << endl;
	cout << countSegments("a") << " 1" << endl;
	cout << countSegments("a ") << " 1" << endl;
	cout << countSegments(" a") << " 1" << endl;
	cout << countSegments(" a ") << " 1" << endl;
	cout << countSegments(" aa ") << " 1" << endl;
	cout << countSegments("aa") << " 1" << endl;
	cout << countSegments("a b") << " 2" << endl;
	cout << countSegments("a b ") << " 2" << endl;
	cout << countSegments(" a b ") << " 2" << endl;
	cout << countSegments(" a  b ") << " 2" << endl;
	cout << countSegments("Hello, my name is John") << " 5" << endl;

}