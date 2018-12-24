/*
https://leetcode.com/problems/is-subsequence/
*/
class Solution {
public:
    bool isSubsequence2(string s, string t) {
        int i = 0;
        int j = 0;
        if (s.empty()) {
            return true;
        }
        while (j < int(t.size())) {
            if (s[i] == t[j]) {
                i++;
                if (i == int(s.size())) {
                    return true;
                }
            }
            ++j;
        }
        return false;
    }
    
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> S;
        for (int i = 0; i < int(t.size()); ++i) {
            S[t[i]].push_back(i);
        }
        int j = -1;
        for(int i = 0; i < int(s.size()); ++i) {
            auto it = upper_bound(S[s[i]].begin(), S[s[i]].end(), j);
            if (it == S[s[i]].end()) {
                return false;
            }
            j = *it;
        }
        return true;
    }

};