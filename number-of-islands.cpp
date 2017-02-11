class Solution {
public:
    void markIsland(vector<vector<char>>& grid, int row, int col) {
        int num_rows = int(grid.size());
        int num_cols = int(grid[0].size());
        if (row >= 0 && row < num_rows && col >= 0 && col < num_cols && grid[row][col] == '1') {
            grid[row][col] = '0';
            markIsland(grid, row + 1, col);
            markIsland(grid, row, col + 1);
            markIsland(grid, row - 1, col);
            markIsland(grid, row, col - 1);
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int res = 0;
        int num_rows = int(grid.size());
        int num_cols = int(grid[0].size());
        for (int row = 0; row < num_rows; row++) {
            for (int col = 0; col < num_cols; col++) {
                if (grid[row][col] == '1') {
                    markIsland(grid, row, col);
                    res++;
                }
            }
        }
        return res;
    }
};