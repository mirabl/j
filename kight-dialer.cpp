// Wrong
class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> next{
            {4, 6}, // 0
            {6, 8}, // 1
            {7, 9}, // 2
            {4, 8}, // 3
            {0, 3, 9}, // 4
            {}, // 5
            {0, 7, 1}, // 6
            {3, 6}, // 7
            {1, 3}, // 8
            {4, 2}}; // 9
        
        int res = 0;
        int mod = 1e9 + 7;
        
        vector<int> dp(10, 1);
        dp[0] = 1;
        for (int t = 0; t < N - 1; t++) {
            vector<int> tmp(10);
            for (int i = 0; i < 10; i++) {
                for (int j: next[i]) {
                    tmp[i] = (tmp[i] + dp[j]) % mod;
                }
            }
            swap(tmp, dp);
        }
    
        for (int i = 0; i < 10; i++) {
            res = (res + dp[i]) % mod;
        }
            
        return N >= 4 ? res - (N - 3) : res;
    }
};
