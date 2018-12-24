/*
https://leetcode.com/problems/word-search/
*/
class Solution {
public:
    bool search(vector<vector<char>>& board, string& word, int offset, int row, int col, vector<vector<int>>& used) {
        if (offset == word.size()) {
            return true;
        }
        char c = word[offset];
        int num_rows = int(board.size());
        int num_cols = int(board[0].size());
        if (row < 0 || row >= num_rows || col < 0 || col >= num_cols || board[row][col] != c || used[row][col] == 1) {
            return false;
        }
        used[row][col] = 1;
        int dr[4] = { 1, -1, 0,  0};
        int dc[4] = { 0,  0, 1, -1};
        for (int i = 0; i < 4; i++) {
            if (search(board, word, offset + 1, row + dr[i], col + dc[i], used)) {
                return true;
            }
        }
        used[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) {
            return word.empty();
        }
        int num_rows = int(board.size());
        int num_cols = int(board[0].size());
        vector<vector<int>> used(num_rows, vector<int>(num_cols, 0));
        for (int row = 0; row < num_rows; row++) {
            for (int col = 0; col < num_cols; col++) {
                if (search(board, word, 0, row, col, used)) {
                    return true;
                }
            }
        }
        return false;
    }
};