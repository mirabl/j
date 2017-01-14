/*
https://leetcode.com/problems/word-break/
*/
class Solution {
public:
    map<int, bool> memo;

    bool wb_rec(string& s, int start, set<string>& S) {
        if (memo.count(start) == 1) {
            return memo[start];
        }
        for (int i = 1; i < 1 + int(s.size()) - start; i++) {
            if (S.count(s.substr(start, i)) == 1) {
                if (wb_rec(s, start + i, S)) {
                    memo[start] = true;
                    return true;
                }
            }
        }
        memo[start] = (start == int(s.size()));
        return memo[start];
    }
    
    bool wb_bottomup(string& s, set<string>& S) {
        const int n = int(s.size());
        bool A[n + 1];
        A[0] = true;
        for (int i = 1; i < n + 1; i++) {
            int j;
            for (j = 0; j < i; j++) {
                if (A[j] && S.count(s.substr(j, i - j)) == 1) {
                    A[i] = true;
                    break;
                }
            }
            if (j == i) {
                A[i] = false;
            }
        }
        return A[n];
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> S;
        for (string t: wordDict) {
            S.insert(t);
        }
        // return wb_rec(s, 0, S);
        return wb_bottomup(s, S);
    }
};