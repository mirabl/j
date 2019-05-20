class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int nrows = A.size();
        int ncols = A[0].size();
        queue<pair<int, int>> Q;

        for (int row = 0; row < nrows; row++) {
            Q.push({row, 0});
            Q.push({row, ncols - 1});
            
        }

        for (int col = 0; col < ncols; col++) {
            Q.push({0, col});
            Q.push({nrows - 1, col});
        }
        while (!Q.empty()) {
            int r = Q.front().first;
            int c = Q.front().second;
            Q.pop();
            if (A[r][c] != 1) {
                continue;
            }
            A[r][c] = 2;
            if (r > 0) {
                Q.push({r - 1, c});
            }
            if (r < nrows - 1) {
                Q.push({r + 1, c});
            }
            if (c > 0) {
                Q.push({r, c - 1});
            }
            if (c < ncols - 1) {
                Q.push({r, c + 1});
            }
        }
        
        int res = 0;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (A[row][col] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};
