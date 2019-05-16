class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> F(60);
        for (auto t: time) {
            F[t % 60]++;
        }
        int res = 0;
        for (int i = 1; i <= 29; i++) {
            res += F[i] * F[(60 - i) % 60];
        }
        res += F[0] * (F[0] - 1) / 2;
        res += F[30] * (F[30] - 1) / 2;
        return res;
    }
};
