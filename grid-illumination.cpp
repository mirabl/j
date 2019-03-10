class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set<pair<int, int>> L;
        map<int, int> byRow, byCol, byDiagUp, byDiagDown;
        for (auto lamp: lamps) {
            int r = lamp[0];
            int c = lamp[1];
            L.insert({r, c});
            byRow[r]++;
            byCol[c]++;
            byDiagUp[c - r]++;
            byDiagDown[c + r]++;
        }
        vector<int> res;
        vector<int> dc{-1, 0, 1, -1, 0, 1, -1, 0, 1};
        vector<int> dr{-1, -1, -1, 0, 0, 0, 1, 1, 1};
        for (auto query: queries) {
            int r = query[0];
            int c = query[1];
            if (byRow[r] > 0 || byCol[c] > 0 || byDiagUp[c - r] > 0 || byDiagDown[c + r] > 0) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
            for (int i = 0; i < dr.size(); i++) {
                int row = r + dr[i];
                int col = c + dc[i];
                if (L.count({row, col}) == 1) {
                    L.erase({row, col});
                    byRow[row]--;
                    byCol[col]--;
                    byDiagUp[col - row]--;
                    byDiagDown[col + row]--;
                }
            }
        }
        return res;
    }
};
