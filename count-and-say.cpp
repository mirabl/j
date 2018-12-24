/*
https://leetcode.com/problems/count-and-say/
38. Count and Say   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 112326
Total Submissions: 346377
Difficulty: Easy
Contributors: Admin
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitSameDigits(string s) {
	vector<string> v;
	if (s.empty()) {
		return v;
	}
	string current_string = s.substr(0, 1);
	for (int i = 1; i < (int)s.size(); ++i) {
		if (s[i] != current_string[0]) {
			v.push_back(current_string);
			current_string = "";
		}
		current_string += s.substr(i, 1);
	}
	v.push_back(current_string);

	return v;
}

string countAndSay(int n) {
	string s;
	if (n == 0) {
		return s;
	}
	s = "1";
	for (int i = 1; i < n; ++i) {
		vector<string> split = splitSameDigits(s);
		s = "";
		for (int j = 0; j < (int)split.size(); ++j) {
			s += to_string(split[j].size()) + split[j][0];
		}
	}
	return s;
}

int main() {
	cout << countAndSay(0) << " ''" << endl;
	cout << countAndSay(1) << " 1" << endl;
	cout << countAndSay(2) << " 11" << endl;
	cout << countAndSay(3) << " 21" << endl;
	cout << countAndSay(4) << " 1211" << endl;
	cout << countAndSay(5) << " 111221" << endl;
	cout << endl;
}