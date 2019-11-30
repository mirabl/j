class Solution {
    boolean ok(char[][] board, int r, int c, char v) {
        for (int rr = 0; rr < 9; rr++) {
            if (board[rr][c] == v) {
                return false;
            }
        }
        for (int cc = 0; cc < 9; cc++) {
            if (board[r][cc] == v) {
                return false;
            }
        }
        int rx = r - (r % 3);
        int cx = c - (c % 3);
        for (int rr = rx; rr < rx + 3; rr++) {
            for (int cc = cx; cc < cx + 3; cc++) {
                if (board[rr][cc] == v) {
                    return false;
                }
            }
        }
        return true;
    }
    
    boolean s(char[][] board) {
        int rr = -1;
        int cc = -1;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    rr = r;
                    cc = c;
                }
            }
        }
        if (rr == -1) {
            return true;
        }
        for (char v = '1'; v <= '9'; v++) {
            if (ok(board, rr, cc, v)) {
                board[rr][cc] = v;
                if (s(board)) {
                    return true;
                }
                board[rr][cc] = '.';
            }
        }
        
        return false;
    }
    
    public void solveSudoku(char[][] board) {
        s(board);
    }
}
