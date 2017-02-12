class Solution {
public:
    int alive_neighbours(vector<vector<int>>& board, int row, int col) {
        const int nrows = int(board.size());
        const int ncols = int(board[0].size());
        int drow[8] = { -1, -1, -1,  0, 0,  1, 1, 1};
        int dcol[8] = { -1,  0,  1, -1, 1, -1, 0, 1};
        int v = 0;
        for (int i = 0; i < 8; i++) {
            int r = row + drow[i];
            int c = col + dcol[i];
            if (r >= 0 && r < nrows && c >= 0 && c < ncols && board[r][c] == 1) {
                v++;
            }
        }
        return v;
    }

    void gameOfLife(vector<vector<int>>& board) {
        const int nrows = int(board.size());
        const int ncols = board.empty() ? 0 : int(board[0].size());
        vector<vector<int>> A(nrows, vector<int>(ncols, 0));
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                int v = alive_neighbours(board, row, col);
                if ((board[row][col] == 1 && (v == 2 || v == 3))
                    || (board[row][col] == 0 && v == 3)) {
                        A[row][col] = 1;
                    }
            }
        }
        board = A;
    }
};