class Solution {
public:
    int distinctSubseqII(string S) {
        int N = S.size();
        int mod = 1e9 + 7;

        vector<int> dp(N);
        for (int i = 0; i < N; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (S[i] == S[j]) {
                    dp[i] = 0;
                }
            }
        }
        for (int i = 1; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                dp[i] = (dp[i] + dp[j]) % mod;
                if (S[i] == S[j]) {
                    break;
                }
            }
        }
        
        for (auto x: dp) {
            cout << x << " ";
        }
        cout << endl;
        
        int res = 0;
        for (int i = 0; i < N; i++) {
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};
