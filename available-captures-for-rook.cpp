class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int nrows = 8;
        int ncols = 8;
        int rrow = -1;
        int rcol = -1;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (board[row][col] == 'R') {
                    rrow = row;
                    rcol = col;
                }
            }
        }
        int res = 0;
        vector<int> dr{1, -1, 0, 0};
        vector<int> dc{0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int row = rrow + dr[i];
            int col = rcol + dc[i];
            while (row >= 0 && row < nrows && col >= 0 && col < ncols) {
                if (board[row][col] == 'B') {
                    break;
                } else if (board[row][col] == 'p') {
                    res++;
                    break;
                }
                row += dr[i];
                col += dc[i];
            }
            
        }
        return res;
    }
};
