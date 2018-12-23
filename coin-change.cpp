class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> A(amount + 1, -1);
        A[0] = 0;
        
        for (int i = 0; i <= amount; i++) {
            for (int c: coins) {
                if (i - c >= 0 && A[i - c] != -1) {
                    int m = 1 + A[i - c];
                    if (A[i] == -1 || A[i] > m) {
                        A[i] = m;
                    }
                }
            }
        }
        return A[amount];
    }
};



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = amount + 1;
        vector<int> A(amount + 1, INF);
        A[0] = 0;
        
        for (int i = 0; i <= amount; i++) {
            for (int c: coins) {
                if (i - c >= 0) {
                    A[i] = min(A[i], 1 + A[i - c]);
                }
            }
        }
        return A[amount] == INF ? -1 : A[amount];
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) {
            return -1;
        }
        int INFTY = 1e8;
        vector<int> dp(amount + 1, INFTY);
        for (int c: coins) {
            if (c > amount) {
                continue;
            }
            dp[c] = 1;
        }
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (auto c: coins) {
                if (i >= c) {
                  dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        
        return dp[amount] != INFTY ? dp[amount] : -1;
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) {
            return -1;
        }
        int INFTY = 1e8;
        vector<int> dp(amount + 1, INFTY);

        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (auto c: coins) {
                if (i >= c) {
                  dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        
        return dp[amount] != INFTY ? dp[amount] : -1;
    }
};

class Solution {
public:
    int infty = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> r(amount + 1, infty);
        r[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int a = coins[i]; a < amount + 1; a++) {
                r[a] = min(r[a], 1 + r[a - coins[i]]);
            }
        }
        return r[amount] == infty ? -1 : r[amount];
    }
};

