/*
https://leetcode.com/problems/sort-characters-by-frequency/

451. Sort Characters By Frequency   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 10187
Total Submissions: 20206
Difficulty: Medium
Contributors: stickypens
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

alias a='g++ -Wall -g sort_characters_by_frequency.cpp && ./a.out'

*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


string frequencySort(string s) {
	// Or ASCII table.
	map<char, int> freq;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (freq.find(s[i]) == freq.end()) {
			freq[s[i]] = 0;
		}
		freq[s[i]]++;
	}
	vector<pair<int, char> > freq_vec;
	for (map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
		freq_vec.push_back(pair<int, char>(it->second, it->first));
	}
	sort(freq_vec.begin(), freq_vec.end());
	string t;
	t.resize(s.size());
	int pos = 0;
	for (int i = freq_vec.size() - 1; i >= 0; --i) {
		for (int j = 0; j < freq_vec[i].first; ++j) {
			t[pos] = freq_vec[i].second;
			++pos;
		}
	}
	return t;
}


int main() {
	cout << frequencySort("tree") << endl;
	cout << frequencySort("cccaaa") << endl;
	cout << frequencySort("Aabb") << endl;

}