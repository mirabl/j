/*
https://leetcode.com/problems/surrounded-regions/

*/
class Solution {
public:
    void markIfFree(vector<vector<char>>& board, int row, int col) {
        int num_rows = int(board.size());
        int num_cols = int(board[0].size());

        queue<pair<int, int>> Q;
        Q.push(pair<int, int>{row, col});
        while (!Q.empty()) {
            pair<int, int> p = Q.front();
            Q.pop();
            row = p.first;
            col = p.second;
            if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
                continue;
            }
            if (board[row][col] == 'O') {
                board[row][col] = 'F';
                Q.push(pair<int, int>{row + 1, col});
                Q.push(pair<int, int>{row - 1, col});            
                Q.push(pair<int, int>{row, col - 1});
                Q.push(pair<int, int>{row, col + 1});
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int num_rows = int(board.size());
        int num_cols = int(board[0].size());
        for (int row = 0; row < num_rows; row++) {
            markIfFree(board, row, 0);
            markIfFree(board, row, num_cols - 1);
        }
        for (int col = 0; col < num_cols; col++) {
            markIfFree(board, 0, col);
            markIfFree(board, num_rows - 1, col);
        }            

        for (int row = 0; row < num_rows; row++) {
            for (int col = 0; col < num_cols; col++) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                } else if (board[row][col] == 'F') {
                    board[row][col] = 'O';
                }
            }
        }
        
    }
};