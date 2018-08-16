// https://leetcode.com/problems/domino-and-tromino-tiling/description/
class Solution {
public:
    int numTilings(int N) {
        long long mod = 1e9 + 7;
        map<int, long long> e, o;
        e[0] = 1;
        for (int n = 1; n <= N; n++) {
            e[n] = (e[n - 2] + e[n - 1] + 2 * o[n - 1]) % mod;
            o[n] = (o[n - 1] + e[n - 2]) % mod;
        }
        return e[N];
    }
};
