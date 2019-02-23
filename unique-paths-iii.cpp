class Solution {
public:
    typedef pair<int, int> pos;
    
    void printPath(set<pos>& S) {
        for (auto p: S) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        map<pair<set<pos>, pos>, int> W;
        int START = 1;
        int END = 2;
        int OK = 0;
        int NOK = -1;
        int nrows = grid.size();
        int ncols = grid[0].size();
        
        int rstart = 0;
        int cstart = 0;
        int rend = 0;
        int cend = 0;
        set<pos> nonObstacle;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (grid[row][col] == START) {
                    rstart = row;
                    cstart = col;
                } else if (grid[row][col] == END) {
                    rend = row;
                    cend = col;
                }
                if (grid[row][col] != NOK) {
                    nonObstacle.insert({row, col});
                }
            }
        }
        
        queue<pair<set<pos>, pos>> Q;
        Q.push({set<pos>{{rstart, cstart}}, {rstart, cstart}});
        W[{set<pos>{{rstart, cstart}}, {rstart, cstart}}] = 1;
        vector<int> dr{1, -1, 0, 0};
        vector<int> dc{0, 0, 1, -1};
        
        int res = 0;
        set<pair<set<pos>, pos>> done;
        while (!Q.empty()) {
            auto z = Q.front();
            Q.pop();
            if (done.count(z) == 1) {
                continue;
            }            
            auto path = z.first;
            auto endingAt = z.second;
            
            for (int i = 0; i < 4; i++) {
                int r = endingAt.first + dr[i];
                int c = endingAt.second + dc[i];
                if (r < 0 || r >= nrows || c < 0 || c >= ncols || grid[r][c] == NOK || path.count({r, c}) == 1) {
                    continue;
                }

                auto newPath = set<pos>(path);
                newPath.insert({r, c});
                W[{newPath, {r, c}}] += W[{path, endingAt}];
                Q.push({newPath, {r, c}});
            }
            done.insert(z);
        }
        
        return W[{nonObstacle, {rend, cend}}];
    }
};
