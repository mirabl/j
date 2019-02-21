class Solution {
public:
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int>> D(m, vector<int>(n));
        D[i][j] = 1;
        vector<int> ri{1, -1, 0, 0};
        vector<int> ci{0, 0, -1, 1};
         int res = 0;
       for (int r = 0; r < N; r++) {
            vector<vector<int>> E(m, vector<int>(n));
            for (int row = 0; row < m; row++) {
                for (int col = 0; col < n; col++) {
                    for (int i = 0; i < 4; i++) {
                        int r = row + ri[i];
                        int c = col + ci[i];
                        if (r < 0 || c < 0 || r >= m || c >= n) {
                            res = (res + D[row][col]) % mod;
                        } else {
                            E[r][c] = (E[r][c] + D[row][col]) % mod;
                        }
                    }
                }
            }
            swap(D, E);
        }

        return res;
    }
};
