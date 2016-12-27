/*
https://leetcode.com/problems/excel-sheet-column-title/
168. Excel Sheet Column Title   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 85394
Total Submissions: 351723
Difficulty: Easy
Contributors: Admin
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

  alias a='g++ -Wall -g excel_sheel_column_title.cpp && ./a.out'
*/
#include <iostream>
#include <string>

using namespace std;

string convertToTitle(int n) {
	string s;
	while (n != 0) {
		int left = (n - 1) % 26;
		char c = 'A' + left;
		s = c + s;
		n = (n - (left + 1)) / 26;
	}
	return s;
}

int main() {
	cout << convertToTitle(1) << endl;
	cout << convertToTitle(26) << endl;
	cout << convertToTitle(27) << endl;
	cout << convertToTitle(28) << endl;
	cout << convertToTitle(26+26) << endl;
	cout << convertToTitle(26+27) << endl;
}