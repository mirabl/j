/*
https://leetcode.com/problems/reverse-vowels-of-a-string/
345. Reverse Vowels of a String   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 58855
Total Submissions: 158172
Difficulty: Easy
Contributors: Admin
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string reverseVowels(string s) {
	string t(s.size(), 0);
	if (s.empty()) {
		return t;
	}

	set<char> vowels;
	vowels.insert('a');
	vowels.insert('e');
	vowels.insert('i');
	vowels.insert('o');
	vowels.insert('u');

	vector<int> vowels_idx;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (vowels.count(tolower(s[i])) == 1) {
			vowels_idx.push_back(i);
		} else {
			t[i] = s[i];
		}
	}
	int num_vowels = (int)vowels_idx.size();
	for (int i = 0; i < num_vowels / 2; ++i) {
		t[vowels_idx[i]] = s[vowels_idx[num_vowels - 1 - i]];
		t[vowels_idx[num_vowels - 1 - i]] = s[vowels_idx[i]];
	}
	if (num_vowels % 2 == 1) {
		t[vowels_idx[num_vowels / 2]] = s[vowels_idx[num_vowels / 2]];
	}
	return t;
}

int main() {
	cout << reverseVowels("a") << " a" << endl;
	cout << reverseVowels("wrt") << " wrt" << endl;
	cout << reverseVowels("awe") << " ewa" << endl;
	cout << reverseVowels("hello") << " holle" << endl;
	cout << reverseVowels("leetcode") << " leotcede" << endl;
	cout << endl;
}