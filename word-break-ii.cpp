/*
https://leetcode.com/problems/word-break-ii/

140. Word Break II   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 75252
Total Submissions: 341501
Difficulty: Hard
Contributors: Admin
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

alias a='g++ -Wall -g -std=c++11 word_break_ii.cpp && ./a.out'

*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;


vector<string> dfs(string& s, unordered_set<string>& wordDict,
	               map<string, vector<string> >& split) {
	// Memoized.
	if (split.count(s) != 0) {
		return split[s];
	}

	vector<string> complete;
	if (s.empty()) {
		complete.push_back("");
	}
	for (int i = 0; i < (int)s.size() + 1; ++i) {
		string head = s.substr(0, i);
		if (wordDict.count(head) != 0) {
			string tail = s.substr(i);
			vector<string> tail_split = dfs(tail, wordDict, split);
			for (int j = 0; j < (int)tail_split.size(); ++j) {
				string r(head);
				if (!tail_split[j].empty()) {
					r += " ";
				}
				r += tail_split[j];
				complete.push_back(r);
			}
		}
	}
	split[s] = complete;
	return complete;
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	map<string, vector<string> > split;
	return dfs(s, wordDict, split);
}

int main() {
	unordered_set<string> wordDict;

	// string s = "catsanddog";
	// wordDict.insert("cat");
	// wordDict.insert("cats");
	// wordDict.insert("and");
	// wordDict.insert("sand");
	// wordDict.insert("dog");
	
	string s = "aaaaaaa";
	wordDict.insert("a");
	wordDict.insert("aa");
	wordDict.insert("aaaa");

//	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//	wordDict.insert("a");
//	wordDict.insert("aa");
//	wordDict.insert("aaa");
//	wordDict.insert("aaaa");
//	wordDict.insert("aaaaa");
//	wordDict.insert("aaaaaa");
//	wordDict.insert("aaaaaaa");
//	wordDict.insert("aaaaaaaa");
//	wordDict.insert("aaaaaaaaa");
//	wordDict.insert("aaaaaaaaaa");

	vector<string> sentence = wordBreak(s, wordDict);
	for (int i = 0; i < (int)sentence.size(); ++i) {
		cout << "'" << sentence[i] << "'" << endl;
	}
}