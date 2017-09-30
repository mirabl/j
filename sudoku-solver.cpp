
class Solution {
public:
    bool valid(vector<vector<char>>& board, int row, int col) {
        set<char> S;
        for (int r = 0; r < 9; r++) {
            if (board[r][col] != '.') {
                if (S.count(board[r][col]) == 1) {
                    return false;
                }
                S.insert(board[r][col]);
            }
        }
        S.clear();
        for (int c = 0; c < 9; c++) {
            if (board[row][c] != '.') {
                if (S.count(board[row][c]) == 1) {
                    return false;
                }
                S.insert(board[row][c]);
            }
        }
        S.clear();
        int rs = row - (row % 3);
        int cs = col - (col % 3);
        for (int r = rs; r < rs + 3; r++) {
            for (int c = cs; c < cs + 3; c++) {
                if (board[r][c] != '.') {
                    if (S.count(board[r][c]) == 1) {
                        return false;
                    }
                    S.insert(board[r][c]);
                }
            }
        }
        return true;
    }

    bool rec(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (int val = 1; val <= 9; val++) {
                        board[row][col] = val + '0';
                        if (valid(board, row, col)) {
                            if (rec(board)) {
                                return true;
                            }
                        }
                        board[row][col] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        rec(board);
    }
};

// simpler check

class Solution {
public:
    bool valid(vector<vector<char>>& board, int row, int col, int val) {
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == '0' + val) {
                return false;
            }
        }
        for (int c = 0; c < 9; c++) {
            if (board[row][c] == '0' + val) {
                return false;
            }
        }
        int rs = row - (row % 3);
        int cs = col - (col % 3);
        for (int r = rs; r < rs + 3; r++) {
            for (int c = cs; c < cs + 3; c++) {
                if (board[r][c] == '0' + val) {
                    return false;
                }
            }
        }
        return true;
    }

    bool rec(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (int val = 1; val <= 9; val++) {
                        if (valid(board, row, col, val)) {
                            board[row][col] = val + '0';
                            if (rec(board)) {
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        rec(board);
    }
};