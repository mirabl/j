
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


//
class Solution {
public:
    bool checkFree(vector<vector<char>>& b, int r, int c, char v) {
        for (int cc = 0; cc < 9; cc++) {
            if (b[r][cc] == v) {
                return false;
            }
        }
        for (int rr = 0; rr < 9; rr++) {
            if (b[rr][c] == v) {
                return false;
            }
        }
        int rc = 3 * (r / 3);
        int cc = 3 * (c / 3);
        for (int ri = 0; ri < 3; ri++) {
            for (int ci = 0; ci < 3; ci++) {
                if (b[rc + ri][cc + ci] == v) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool s(vector<vector<char>>& b) {
        int r, c;
        for (r = 0; r < 9; r++) {
            for (c = 0; c < 9; c++) {
                if (b[r][c] == '.') {
                    break;
                }
            }
            if (b[r][c] == '.') {
                break;
            }
        }
        if (r >= 9) {
            return true;
        }
        
        for (char v = '1'; v <= '9'; v++) {
            if (checkFree(b, r, c, v)) {
                b[r][c] = v;
                if (s(b)) {
                    return true;
                }
            }
        }
        b[r][c] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        s(board);
    }
};


class Solution {
public:
    bool possible(vector<vector<char>>& b, int r, int c, char v) {
        for (int col = 0; col < 9; col++) {
            if (b[r][col] == v) {
                return false;
            }
        }
        for (int row = 0; row < 9; row++) {
            if (b[row][c] == v) {
                return false;
            }
        }
        
        int rt = r - (r % 3);
        int ct = c - (c % 3);
        for (int row = rt; row < rt + 3; row++) {
            for (int col = ct; col < ct + 3; col++) {
                if (b[row][col] == v) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool rec(vector<vector<char>>& b) {
        int r = -1, c = -1;
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (b[row][col] == '.') {
                    r = row;
                    c = col;
                }
             }
        }
        
        if (r == -1) {
            return true;
        }
        
        for (char v = '1'; v <= '9'; v++) {
            if (possible(b, r, c, v)) {
                b[r][c] = v;
                if (rec(b)) {
                    return true;
                }
                b[r][c] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        rec(board);
    }
};




class Solution {
public:
    bool checkChar(vector<vector<char>>& b, int row, int col, char v) {
        for (int c = 0; c < 9; c++) {
            if (b[row][c] == v) {
                return false;
            }
        }
        for (int r = 0; r < 9; r++) {
            if (b[r][col] == v) {
                return false;
            }
        }
        int rr = row - (row % 3);
        int cc = col - (col % 3);
        for (int r = rr; r < rr + 3; r++) {
            for (int c = cc; c < cc + 3; c++) {
                if (b[r][c] == v) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool r(vector<vector<char>>& b) {
        int row = -1;
        int col = -1;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (b[r][c] == '.') {
                    row = r;
                    col = c;
                }
            }
        }
        
        if (row == -1) {
            return true;
        }
        
        for (char v = '1'; v <= '9'; v++) {
            if (!checkChar(b, row, col, v)) {
                continue;
            }
            
            b[row][col] = v;
            if (r(b)) {
                return true;
            }
            b[row][col] = '.';
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        r(board);
    }
};
