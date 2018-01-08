class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int kBound = 100 * 100;
        vector<vector<int>> D(N, vector<int>(N, kBound));
        for (vector<int>& v: times) {
            D[v[0] - 1][v[1] - 1] = v[2];
        }
        for (int i = 0; i < N; i++) {
            D[i][i] = 0;
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
        int res = D[K - 1][0];
        for (int i = 1; i < N; i++) {
            res = max(res, D[K - 1][i]);
        }
        
        return res < kBound ? res : -1;
    }
};