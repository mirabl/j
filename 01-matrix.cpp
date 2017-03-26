class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = matrix.empty() ? 0 : matrix[0].size();
        vector<vector<int>> D(nrows, vector<int>(ncols, nrows + ncols + 1));
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (matrix[row][col] == 0) {
                    D[row][col] = 0;
                }
            }
        }
        
        vector<int> dr{1, -1, 0, 0};
        vector<int> dc{0, 0, 1, -1};
        
        for (int d = 1; d <= nrows + ncols; d++) {
            for (int row = 0; row < nrows; row++) {
                for (int col = 0; col < ncols; col++) {
                    if (D[row][col] == d - 1) {
                        for (int i = 0; i < 4; i++) {
                            int r = row + dr[i];
                            int c = col + dc[i];
                            if (r >= 0 && r < nrows && c >= 0 && c < ncols) {
                                D[r][c] = min(D[r][c], D[row][col] + 1);
                            }
                        }
                    }
                }
            }
        }
        return D;
    }
};

// better: BFS
// https://discuss.leetcode.com/topic/83559/simple-bfs-idea