
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


class Solution {
public:
    bool s(vector<vector<char>>& board) {
        int row = -1, col = -1;
        for (int i = 0; i < 9 && row == -1; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        
        if (row == -1) {
            return true;
        }
        
        for (char v = '1'; v <= '9'; v++) {
            bool ok = true;
            for (int col2 = 0; col2 < 9; col2++) {
                if (board[row][col2] == v) {
                    ok = false;
                }
            }
            for (int row2 = 0; row2 < 9; row2++) {
                if (board[row2][col] == v) {
                    ok = false;
                }
            }
            
            int rowb = 3 * (row / 3);
            int colb = 3 * (col / 3);
            for (int r = rowb; r < rowb + 3; r++) {
                for (int c = colb; c < colb + 3; c++) {
                    if (board[r][c] == v) {
                        ok = false;
                    }
                }
            }
            
            if (!ok) {
                continue;
            }
            
            board[row][col] = v;
            if (s(board)) {
                return true;
            }
            board[row][col]= '.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        s(board);
    }
};
