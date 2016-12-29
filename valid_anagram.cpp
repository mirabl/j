/*
https://leetcode.com/problems/valid-anagram/

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

alias a='g++ -Wall -std=c++11 valid_anagram.cpp && ./a.out'
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isAnagram2(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}
	int freq[256] = { 0 };
	for (int i = 0; i < (int)s.size(); ++i) {
		freq[(int)s[i]]++;
		freq[(int)t[i]]--;
	}
	for (int i = 0; i < 256; ++i) {
		if (freq[i] != 0) {
			return false;
		}
	}
	return true;
}

bool isAnagram(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}
	map<char, int> M;
	for (int i = 0; i < (int)s.size(); ++i) {
		M[s[i]]++;
		M[t[i]]--;
	}
	for (map<char, int>::iterator it = M.begin(); it != M.end(); ++it) {
		if (it->second != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << isAnagram("", "") << " 1" << endl;
	cout << isAnagram("a", "") << " 0" << endl;
	cout << isAnagram("a", "a") << " 1" << endl;
	cout << isAnagram("a", "ab") << " 0" << endl;
	cout << isAnagram("ba", "ab") << " 1" << endl;
	cout << isAnagram("anagram", "nagaram") << " 1" << endl;
	cout << isAnagram("rat", "car") << " 0" << endl;
}