class Solution {
public:
    typedef vector<vector<int>> board_t;
    
    bool isSolved(board_t& board) {
        return board[0] == vector<int>{1, 2, 3} && board[1] == vector<int>{4, 5, 0};
    }
    
    int findRowZero(board_t& board) {
        if (board[0][0] == 0 || board[0][1] == 0 || board[0][2] == 0) {
            return 0;
        }
        return 1;
    }
    
    int findColZero(board_t& board) {
        for (int col = 0; col <= 2; col++) {
            if (board[0][col] == 0 || board[1][col] == 0) {
                return col;
            }
        }
        return -1; // Not reached.
    }
    
    void printBoard(board_t& board) {
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 3; col++) {
                cout << board[row][col];
            }
            cout << endl;
        }
    }
    
    int solve(board_t& board) {
        int steps = 0;
        queue<board_t> Q;
        Q.push(board);
        set<board_t> visited;

        while (!Q.empty()) {
            int n = Q.size();
            while (n > 0) {
                auto b = Q.front();
                Q.pop();
                if (isSolved(b)) {
                    return steps;
                }
                visited.insert(b);
                int row0 = findRowZero(b);
                int col0 = findColZero(b);
                for (int i = 0; i < 4; i++) {
                    int rowN = row0 + vector<int>{1, -1, 0, 0}[i];
                    int colN = col0 + vector<int>{0, 0, 1, -1}[i];
                    if (rowN >= 0 && rowN <= 1 && colN >= 0 && colN <= 2) {
                        auto b2 = b;
                        swap(b2[row0][col0], b2[rowN][colN]);
                        if (visited.count(b2) == 0) {
                            Q.push(b2);
                        }
                    }
                }
                n--;
            }
            steps++;
        }
        return -1;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        return solve(board);
    }
};