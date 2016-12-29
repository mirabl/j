/*

alias a='co AnagramFree.cpp && ./a.out'
*/
#include <string>
#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class AnagramFree {
public: 
	bool isAnagram(const string& s, const string& t) {
		if (s.size() != t.size()) {
			return false;
		}
		int freq[26];
		for (int i = 0; i < 26; ++i) {
			freq[i] = 0;
		}

		for (int i = 0; i < (int)s.size(); ++i) {
			freq[int(s[i] - 'a')]++;
			freq[int(t[i] - 'a')]--;
		}

		for (int i = 0; i < 26; ++i) {
			if (freq[i] != 0) {
				return false;
			}
		}
		return true;
	}
	int getMaximumSubset(vector <string> S) {
		int n = (int)S.size();
		vector<vector<string> > buckets;
		for (int i = 0; i < n; ++i) {
			int j = 0;
			for (; j < (int)buckets.size(); ++j) {
				if (isAnagram(S[i], buckets[j][0])) {
					buckets[j].push_back(S[i]);
					break;
				}
			}
			if (j == (int)buckets.size()) {
				vector<string> nb;
				buckets.push_back(nb);
				buckets[j].push_back(S[i]);
			}
		}
		return (int)buckets.size();
	}
};

int main() {
	AnagramFree A;
	cout << A.getMaximumSubset(vector<string>{"abcd","abac","aabc","bacd"}) << " 2" << endl;
	cout << A.getMaximumSubset(vector<string>{"creation","sentence","reaction","sneak","star","rats","snake"}) << " 4" << endl;
}