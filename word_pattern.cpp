/*
https://leetcode.com/problems/word-pattern/
290. Word Pattern   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 61995
Total Submissions: 194107
Difficulty: Easy
Contributors: Admin
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<string> splitOnSpaces(string s) {
	vector<string> v;
	istringstream iss(s); 
	string x;
	while (iss >> x) {
		v.push_back(x);
	}
	return v;
}

bool wordPattern2(string pattern, string str) {
	vector<string> words = splitOnSpaces(str);
	if (pattern.size() != words.size()) {
		return false;
	}

	map<char, string> charToWord;
	map<string, char> wordToChar;  // Could be a set.
	for (int i = 0; i < (int)pattern.size(); ++i) {
		if ((charToWord.count(pattern[i]) != 0 && charToWord[pattern[i]] != words[i])
			|| (wordToChar.count(words[i]) != 0 && wordToChar[words[i]] != pattern[i])) {
			return false;
		}
		charToWord[pattern[i]] = words[i];
		wordToChar[words[i]] = pattern[i];
	}
	return true;
}

bool wordPattern(string pattern, string str) {
	vector<string> words = splitOnSpaces(str);
	if (pattern.size() != words.size()) {
		return false;
	}

	map<char, int> charIndex;
	map<string, int> wordIndex;
	int e = 1;
	for (int i = 0; i < (int)pattern.size(); ++i) {
		if (charIndex[pattern[i]] != wordIndex[words[i]]) {
			return false;
		}
		if (charIndex[pattern[i]] == 0) {
			charIndex[pattern[i]] = e;
			wordIndex[words[i]] = e;
			++e;
		}
	}
	return true;
}


int main() {
	cout << wordPattern("abba", "dog cat cat dog") << " 1" << endl;
	cout << wordPattern("abba", "dog cat cat fish") << " 0" << endl;
	cout << wordPattern("aaaa", "dog cat cat dog") << " 0" << endl;
	cout << wordPattern("abba", "dog dog dog dog") << " 0" << endl;
	cout << endl;
}