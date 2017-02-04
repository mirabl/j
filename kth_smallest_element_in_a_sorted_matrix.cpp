class Solution {
public:
    int kthSmallest(vector<vector<int>>& M, int k) {
        priority_queue<pair<int, pair<int, int>>> Q;
        const int n = int(M.size());
        vector<vector<int>> visited(n, vector<int>(n, false));
        Q.push({- M[0][0], {0, 0}});
        visited[0][0] = true;

        while (k > 1) {
            auto x = Q.top();
            Q.pop();
            int drow[2] = {1, 0};
            int dcol[2] = {0, 1};
            for (int i = 0; i < 2; i++) {
                int r = x.second.first + drow[i];
                int c = x.second.second + dcol[i];
                if (r < n && c < n && !visited[r][c]) {
                    Q.push({- M[r][c], {r, c}});
                    visited[r][c] = true;
                }
            }
            k--;
        }
    
        return - Q.top().first;
    }
};