/*
https://leetcode.com/problems/generate-parentheses/

22. Generate Parentheses   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 121365
Total Submissions: 292236
Difficulty: Medium
Contributors: Admin
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

alias a='g++ -std=c++11 -Wall generate_parentheses.cpp && ./a.out'

*/
#include <iostream>
#include <vector>

using namespace std;

void generate_rec(string& prefix, int remaining_open, int active_open, vector<string>& res) {
	if (remaining_open == 0 && active_open == 0) {
		res.push_back(prefix);
		return;
	}
	if (remaining_open > 0) {
		prefix.push_back('(');
		generate_rec(prefix, remaining_open - 1, active_open + 1, res);
		prefix.pop_back();
	}
	if (active_open > 0) {
		prefix.push_back(')');
		generate_rec(prefix, remaining_open, active_open - 1, res);
		prefix.pop_back();
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	string s;
	generate_rec(s, n, 0, res);
	return res;
}

int main() {
	vector<string> res;
	res = generateParenthesis(3);
	for (int i = 0; i < (int)res.size(); ++i) {
		cout << res[i] << endl;
	}
}