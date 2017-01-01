/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
438. Find All Anagrams in a String   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 12140
Total Submissions: 36200
Difficulty: Easy
Contributors: Stomach_ache
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> findAnagrams(string s, string p) {
	vector<int> r;
	map<char, int> F;
	int n = (int)s.size();
	int m = (int)p.size();
	if (n < m || n == 0) {
		return r;
	}
	for (int i = 0; i < m; ++i) {
		F[p[i]]++;
	}

	for (int i = 0; i < m; ++i) {
		F[s[i]]--;
	}

	for (int i = m; i < n + 1; ++i) {
		map<char, int>::iterator it = F.begin();
		for (; it != F.end(); ++it) {
			if (it->second != 0) {
				break;
			}
		}
		if (it == F.end()) {
			r.push_back(i - m);
		}
		if (i == n) {
			continue;
		}
		F[s[i - m]]++;
		F[s[i]]--;
	}

	return r;
}

void print_vector(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
}

int main() {
	print_vector(findAnagrams("cbaebabacd", "abc"));
	cout << " 0, 6" << endl;
	cout << endl;
}