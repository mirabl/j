class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const int nrows = grid.size();
        const int ncols = grid[0].size();
        vector<int> maxByRow;
        for (int row = 0; row < nrows; row++) {
            int m = 0;
            for (int col = 0; col < ncols; col++) {
                m = max(m, grid[row][col]);
            }
            maxByRow.push_back(m);
        }
        vector<int> maxByCol;
        for (int col = 0; col < ncols; col++) {
            int m = 0;
            for (int row = 0; row < nrows; row++) {
                m = max(m, grid[row][col]);
            }
            maxByCol.push_back(m);
        }
        
        int res = 0;
        for (int row = 0; row < nrows; row++) {
           for (int col = 0; col < ncols; col++) {
               res += min(maxByRow[row], maxByCol[col]) - grid[row][col];
           }
        }
        return res;
    }
};