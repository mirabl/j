/*
https://leetcode.com/problems/compare-version-numbers/
165. Compare Version Numbers   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 74069
Total Submissions: 386794
Difficulty: Easy
Contributors: Admin
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:

alias a='g++ -Wall -std=c++11 compare_version_numbers.cpp && ./a.out'

*/
#include <iostream>
#include <string>

using namespace std;

// Slow and not very clean.
int compareVersion(string version1, string version2) {
	string s1(version1);
	string s2(version2);

	size_t a_pos = 0;
	size_t b_pos = 0;
	int a_int; 
	int b_int; 

	while (!s1.empty() || !s2.empty()) {
		a_int = atoi(s1.c_str()); // atoi("") = 0.
		b_int = atoi(s2.c_str());

		if (a_int > b_int) {
			return 1;
		} else if (a_int < b_int) {
			return -1;
		}

		a_pos = s1.find('.');
		if (a_pos == string::npos) {
			s1 = "";
		} else {
			s1 = s1.substr(a_pos + 1);
		}
		b_pos = s2.find('.');
		if (b_pos == string::npos) {
			s2 = "";
		} else {
			s2 = s2.substr(b_pos + 1);
		}
	}
	return 0;
}

int main() {
	cout << compareVersion("0.1", "1.1") << " -1" << endl;
	cout << compareVersion("1.1", "1.2") << " -1" << endl;
	cout << compareVersion("1.2", "13.37") << " -1" << endl;
	cout << compareVersion("1.1", "0.1") << " 1" << endl;
	cout << compareVersion("1.1", "1.1") << " 0" << endl;
	cout << compareVersion("0.1", "0.10") << " -1" << endl;
	cout << compareVersion("13.100", "13.10") << " 1" << endl;
	cout << compareVersion("1.1", "1") << " 1" << endl;
	cout << compareVersion("1.0", "1") << " 0" << endl;
	cout << compareVersion("1.0.1", "1") << " 1" << endl;
	cout << compareVersion("1.2.3", "1.2.4") << " -1" << endl;
}
