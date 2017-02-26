class Solution {
public:
    int longestPalindromeSubseq(string s) {
     int n = s.size();
     vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
     for (int i = 0; i < n; i++) {
         M[i][1] = 1;
     }
     for (int k = 2; k <= n; k++) {
         for (int i = 0; i < n; i++) {
             M[i][k] = max(M[i][k - 1], M[i + 1][k - 1]);
             if (i + k - 1 < n && s[i] == s[i + k - 1]) {
                 M[i][k] = max(M[i][k], 2 + M[i + 1][k - 2]);
             }
         }
     }
     return M[0][n];
    }
};