class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> M(n + 1, vector<int>(m + 1));
        for (int col = 0; col <= m; col++) {
            M[0][col] = col;
        }
        for (int row = 1; row <= n; row++) {
            M[row][0] = row;
        }
        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= m; col++) {
                if (word1[row - 1] == word2[col - 1]) {
                    M[row][col] = M[row - 1][col - 1];
                } else {
                    M[row][col] = 1 + min(M[row - 1][col], M[row][col - 1]);
                }
            }
        }
        return M[n][m];
    }
};