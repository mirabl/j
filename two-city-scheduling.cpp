class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // best[untilPersonI][withKInCityA]
        int N = costs.size();
        int infty = 1e9;
        vector<vector<int>> best(N, vector<int>(N, infty));
        best[0][0] = costs[0][1];
        best[0][1] = costs[0][0];
        for (int i = 1; i < N; i++) {
            for (int k = 0; k < N; k++) {
                best[i][k] = best[i - 1][k] + costs[i][1];
                if (k > 0) {
                    best[i][k] = min(best[i][k], best[i - 1][k - 1] + costs[i][0]);
                }
            }
        }
        return best[N - 1][N / 2];
    }
};
