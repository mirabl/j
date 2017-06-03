class Solution {
public:
    bool match(string& s, string& p, int i, int j, map<pair<int, int>, bool>& memo) {
        if (memo.count({i, j}) == 0) {
            if (i == s.size() && j == p.size()) {
                memo[{i, j}] = true;
            } else if (p[j] == '*') {
                memo[{i, j}] = match(s, p, i, j + 1, memo) || (i < s.size() && match(s, p, i + 1, j, memo));
            } else {
                memo[{i, j}] = (s[i] == p[j] || p[j] == '?') && match(s, p, i + 1, j + 1, memo);
            }
        }
        return memo[{i, j}];
    }

    bool isMatch(string s, string p) {
        map<pair<int, int>, bool> memo;
        return match(s, p, 0, 0, memo);
    }
};

// DP
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> M(n + 1, vector<bool>(m + 1, false));

        M[n][m] = true;
        for (int j = m - 1; j >= 0; j--) {
            M[n][j] = M[n][j + 1] && p[j] == '*';
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (p[j] == '*') {
                    M[i][j] = M[i][j + 1] || M[i + 1][j];
                }
                if (s[i] == p[j] || p[j] == '?') {
                    M[i][j] = M[i + 1][j + 1];
                }
            }
        }
        return M[0][0];
    }