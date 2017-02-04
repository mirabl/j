class Solution {
public:
    int integerBreak(int n) {
        vector<int> P(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                P[i] = max(P[i], P[j] * P[i - j]);
            }
            if (i == n) {
                break;
            }
            P[i] = max(P[i], i);
        }
        return P[n];
    }
};