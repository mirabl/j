class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<pair<int, vector<int>>> V;
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                int d = abs(row - r0) + abs(col - c0);
                V.push_back({d, {row, col}});
            }
        }
        sort(V.begin(), V.end());
        
        vector<vector<int>> res;
        for (auto p: V) {
            res.push_back(p.second);
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        queue<vector<int>> Q;
        Q.push({r0, c0});
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            int r = p[0];
            int c = p[1];
            if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c]) {
                continue;
            }
            
            res.push_back(p);
            visited[r][c] = true;
            
            Q.push({r - 1, c});
            Q.push({r + 1, c});
            Q.push({r, c - 1});
            Q.push({r, c + 1});            
        }
        
        return res;
    }
};
