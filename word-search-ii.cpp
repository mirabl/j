class Solution {
public:
    int nrows, ncols;
    set<string> res;
    set<string> W;
    vector<int> dr{1, -1, 0, 0};
    vector<int> dc{0, 0, -1, 1};
    set<string> allPrefixes;

    void dfs(vector<vector<char>>& board, int row, int col, string& s) {
        if (row < 0 || row >= nrows || col < 0 || col >= ncols) {
            return;
        }
        
        char c = board[row][col];
        board[row][col] = 'X';
        s.push_back(c);
        
        if (W.count(s) == 1) {
            res.insert(s);
        }

        if (allPrefixes.count(s) == 1) {
            for (int i = 0; i < 4; i++) {
                int row2 = row + dr[i];
                int col2 = col + dc[i];
                dfs(board, row2, col2, s);
            }
        }
        
        board[row][col] = c;
        s.resize(s.size() - 1);
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        nrows = board.size();
        ncols = board[0].size();
        for (auto w: words) {
            W.insert(w);
        }
        
        for (auto w: words) {
            for (int i = 1; i < w.size(); i++) {
                allPrefixes.insert(w.substr(0, i));
            }
        }
        
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                string s;
                dfs(board, row, col, s);
            }
        }
        
        vector<string> v(res.begin(), res.end());
        return v;
    }
};

// better with prefix tree?

class Solution {
public:
    vector<vector<char>> B;
    set<string> W;
    set<string> resS;
    int nrows, ncols;
    set<string> prefixes;
    
    void dfs(int row, int col, string& cur) {
        if (B[row][col] == 'X' || prefixes.count(cur) == 0) {
            return;
        }
        
        int tmp = B[row][col];
        cur += B[row][col];
        B[row][col] = 'X';
        if (W.count(cur) == 1) {
            resS.insert(cur);
        }  
        
        for (int i = 0; i < 4; i++) {
            int rn = row + vector<int>{1, -1, 0, 0}[i];
            int cn = col + vector<int>{0, 0, 1, -1}[i];
            if (rn >= 0 && rn < nrows && cn >= 0 && cn < ncols) {
                dfs(rn, cn, cur);
            }
        }
        B[row][col] = tmp;
        cur.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board_, vector<string>& words) {
        B = board_;
        for (auto w: words) {
            W.insert(w);
            for (int i = 0; i <= w.size(); i++) {
                prefixes.insert(w.substr(0, i));
            }
        }
        
        nrows = B.size();
        ncols = B[0].size();
        
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                string cur;
                dfs(row, col, cur);
            }
        }
        return vector<string>(resS.begin(), resS.end());
    }
};

