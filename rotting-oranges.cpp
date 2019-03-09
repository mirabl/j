class Solution {
public:
    int kFresh = 1;
    int kRotten = 2;
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = grid[0].size();
        int nFresh = 0;
        queue<pair<int, int>> newRotten;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (grid[row][col] == kFresh) {
                    nFresh++;
                } else if (grid[row][col] == kRotten) {
                    newRotten.push({row, col});
                }
            }
        }
        
        int t = 0;
        queue<pair<int, int>> nextRotten;
        while (nFresh > 0) {
            t++;
            while (!newRotten.empty()) {
                auto p = newRotten.front();
                newRotten.pop();
                int row = p.first;
                int col = p.second;
                if (row < nrows - 1 && grid[row + 1][col] == kFresh) {
                    grid[row + 1][col] = kRotten;
                    nextRotten.push({row + 1, col});
                    nFresh--;
                }
                if (row > 0 && grid[row - 1][col] == kFresh) {
                    grid[row - 1][col] = kRotten;
                    nextRotten.push({row - 1, col});
                    nFresh--;
                }

                if (col < ncols - 1 && grid[row][col + 1] == kFresh) {
                    cout << "  hba" << endl;
                    grid[row][col + 1] = kRotten;
                    nextRotten.push({row, col + 1});
                    nFresh--;
                }

                if (col > 0 && grid[row][col - 1] == kFresh) {
                    grid[row][col - 1] = kRotten;
                    nextRotten.push({row, col - 1});
                    nFresh--;
                }
            }

            if (nextRotten.empty()) {
                return -1;
            }
            swap(newRotten, nextRotten);
            
        }

        return t;
    }
};
