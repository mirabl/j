class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        int INFTY = 1e8;
        vector<vector<int>> dp(N, vector<int>(N));
        for (int row = N - 1; row >= 0; row--) {
            for (int col = 0; col < N; col++) {
                dp[row][col] = A[row][col];
                if (row < N - 1) {
                    set<int> v;
                    dp[row][col] += min(min(dp[row + 1][col], 
                                            col < N - 1 ? dp[row + 1][col + 1] : INFTY), 
                                        col > 0 ? dp[row + 1][col - 1] : INFTY);
                }
            }
        }
        
        int res = INFTY;
        for (int col = 0; col < N; col++) {
            res = min(res, dp[0][col]);
        }
        
        return res;
    }
};
