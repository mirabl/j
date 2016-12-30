/*
https://leetcode.com/problems/ransom-note/
383. Ransom Note   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 35176
Total Submissions: 76543
Difficulty: Easy
Contributors: Admin
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	if (ransomNote.empty()) {
		return true;
	}    
	map<char, int> F;
	for (int i = 0; i < (int)ransomNote.size(); ++i) {
		F[ransomNote[i]]++;
	}
	for (int i = 0; i < (int)magazine.size(); ++i) {
		F[magazine[i]]--;
	}
	for (map<char, int>::iterator it = F.begin(); it != F.end(); ++it) {
		if (it->second > 0) {
			return false;
		}
	}
	return true;
}


int main() {
	cout << canConstruct("", "") << " 1" << endl;
	cout << canConstruct("a", "") << " 0" << endl;
	cout << canConstruct("", "a") << " 1" << endl;
	cout << canConstruct("a", "b") << " 0" << endl;
	cout << canConstruct("aa", "ab") << " 0" << endl;
	cout << canConstruct("aa", "aab") << " 1" << endl;
}