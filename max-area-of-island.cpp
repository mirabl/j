class Solution {
public:
    int sizeOfIsland(vector<vector<int>>& grid, int row, int col) {
        if (!(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
            || grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        return 1 + sizeOfIsland(grid, row + 1, col) + sizeOfIsland(grid, row - 1, col) + sizeOfIsland(grid, row, col + 1) + sizeOfIsland(grid, row, col - 1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int nrows = grid.size();
        int ncols = nrows > 0 ? grid[0].size() : 0;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                res = max(res, sizeOfIsland(grid, row, col));
            }
        }
        return res;
    }
};

class Solution {
public:
    int sizeOfIsland(vector<vector<int>>& grid, int row, int col) {
        if (!(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
            || grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        int res = 1;
        vector<int> drow{1, -1, 0, 0};
        vector<int> dcol{0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            res += sizeOfIsland(grid, row + drow[i], col + dcol[i]);
        }
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int nrows = grid.size();
        int ncols = nrows > 0 ? grid[0].size() : 0;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                res = max(res, sizeOfIsland(grid, row, col));
            }
        }
        return res;
    }
};

