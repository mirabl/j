class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> C;
        int m = 0;
        for (vector<int> const & row: wall) {
            int s = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                s += row[i];
                C[s]++;
                m = max(m, C[s]);
            }
        }
        return wall.size() - m;
    }
};