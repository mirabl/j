class Solution {
public:
    bool check(vector<vector<int>>& grid, int row, int col) {
        set<int> T{
            grid[row][col], grid[row][col + 1], grid[row][col + 2],
            grid[row + 1][col], grid[row + 1][col + 1], grid[row + 1][col + 2],
            grid[row + 2][col], grid[row + 2][col + 1], grid[row + 2][col + 2]
        };
        
        for (auto x: T) {
            if (x < 1 || x > 9) {
                return false;
            }
        }
        
        if (T.size() != 9) {
            return false;
        }
        
        set<int> S{
            grid[row][col] + grid[row][col + 1] + grid[row][col + 2],
            grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2],
            grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2],
            
            grid[row][col] + grid[row + 1][col] + grid[row + 2][col],
            grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1],
            grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2],
            
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2],
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2]
        };
        
        return S.size() == 1;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = grid[0].size();
        int ans = 0;
        
        for (int row = 0; row < nrows - 2; row++) {
            for (int col = 0; col < ncols - 2; col++) {
                ans += check(grid, row, col) ? 1 : 0;
            }
        }
        return ans;
    }
};
