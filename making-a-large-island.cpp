// contest
class Solution {
public:
    const int NOT_VISITED = -1;
    
    vector<int> drow{1, -1, 0, 0};
    vector<int> dcol{0, 0, -1, 1};
    int nrows, ncols;
    
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& island, int row, int col, int islandNumber) {
        if (grid[row][col] == 0 || island[row][col] != NOT_VISITED) {
            return 0;
        }
        island[row][col] = islandNumber;
        int s = 1;
        for (int i = 0; i < 4; i++) {
            int row2 = row + drow[i];
            int col2 = col + dcol[i];
            if (row2 >= 0 && row2 < nrows && col2 >= 0 && col2 < ncols) {
                s += dfs(grid, island, row2, col2, islandNumber);
            }
        }
        return s;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        nrows = grid.size();
        ncols = grid[0].size();
        vector<vector<int>> island(nrows, vector<int>(ncols, NOT_VISITED));
        
        vector<int> sizes;
        
        int islandNumber = 0;
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                if (grid[i][j] == 1 && island[i][j] == NOT_VISITED) {
                    int size = dfs(grid, island, i, j, islandNumber);
                    sizes.push_back(size);
                    islandNumber++;
                }
            }
        }
        
        sizes.push_back(0);
        int m = *max_element(sizes.begin(), sizes.end());
        
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (grid[row][col] == 0) {
                    int merged = 1;
                    set<int> I;
                    for (int i = 0; i < 4; i++) {
                        int row2 = row + drow[i];
                        int col2 = col + dcol[i];
                        if (row2 >= 0 && row2 < nrows && col2 >= 0 && col2 < ncols) {
                            I.insert(island[row2][col2]);
                        }
                    }
                    for (int is: I) {
                        merged += sizes[is];
                    }
                    m = max(m, merged);
                }
            }
        }
        
        return m;
    }
};
