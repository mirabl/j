class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        int nrows = obstacleGrid.size();
        int ncols = obstacleGrid[0].size();
        vector<vector<int>> A(nrows, vector<int>(ncols, 0));
        A[0][0] = obstacleGrid[0][0] ^ 1;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (obstacleGrid[row][col] == 0) {
                    A[row][col] += row > 0 ? A[row - 1][col] : 0;
                    A[row][col] += col > 0 ? A[row][col - 1] : 0;
                }
            }
        }
        return A[nrows - 1][ncols - 1];
    }
};