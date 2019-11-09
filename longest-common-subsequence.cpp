class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> T(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);
                if (text1[i - 1] == text2[j - 1]) {
                    T[i][j] = max(T[i][j], 1 + T[i - 1][j - 1]);
                }
            }
        }
        return T[n][m];
    }
};

