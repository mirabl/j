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

