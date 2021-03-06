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

class Solution {
public:
    set<string> W;
    int nrows, ncols;
    char end = 0;
    vector<bool> found;
    struct TrieNode {
        TrieNode* children[26];
        int word;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            word = -1;
        }
    };
    TrieNode *root;
    
    void dfs(vector<vector<char>>& B, vector<string>& words, int row, int col, TrieNode *n) {
        int tmp = B[row][col];
        n = n->children[tmp - 'a'];
        if (!n) {
            return;
        }
        if (n->word != -1) {
            found[n->word] = true;
        }
        
        B[row][col] = 'X';
        for (int i = 0; i < 4; i++) {
            int rn = row + vector<int>{1, -1, 0, 0}[i];
            int cn = col + vector<int>{0, 0, 1, -1}[i];
            if (rn >= 0 && rn < nrows && cn >= 0 && cn < ncols && B[rn][cn] != 'X' && n->children[B[rn][cn] - 'a'] != NULL) {
                dfs(B, words, rn, cn, n);
            }
        }
        B[row][col] = tmp;
    }
       
    bool hasPrefix2(string& s) {
        TrieNode *n = root;
        for (char c: s) {
            if (n->children[c - 'a'] == NULL) {
                return false;
            }
            n = n->children[c - 'a'];
        }
        return true;
    }
    
   void insertWord(int i, string s) {
        TrieNode *n = root;
        for (char c: s) {
            if (n->children[c - 'a'] == NULL) {
                n->children[c - 'a'] = new TrieNode();
            }
            n = n->children[c - 'a'];
        }
       n->word = i;
    }
        
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        found = vector<bool>(words.size(), false);
        for (int i = 0; i < words.size(); i++) {
            insertWord(i, words[i]);
        }
        
        nrows = board.size();
        ncols = board[0].size();
        
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                dfs(board, words, row, col, root);
            }
        }
        vector<string> res;
        
        for (int i = 0; i < words.size(); i++) {
            if (found[i]) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};


struct TrieNode {
    bool leaf;
    string s;
    map<char, TrieNode*> children;
};

class Solution {
public:
    TrieNode *root;
    int nrows;
    int ncols;
    set<string> found;
    void insertWord(string& w) {
        TrieNode *p = root;
        for (auto c: w) {
            if (p->children.count(c) == 0) {
                p->children[c] = new TrieNode();
                p->children[c]->leaf = false;
            }
            p = p->children[c];
        }
        p->leaf = true;
        p->s = w;
    }
    
    void dfs(int row, int col, vector<vector<char>>& board, TrieNode* cur) {
        if (row < 0 || row >= nrows || col < 0 || col >= ncols) {
            return;
        }
        cur = cur->children[board[row][col]];

        if (cur == NULL) {
            return;
        }
        char v = board[row][col];
        board[row][col] = ' ';        
        if (cur->leaf) {
            found.insert(cur->s);
        }
        
        dfs(row + 1, col, board, cur);
        dfs(row - 1, col, board, cur);
        dfs(row, col + 1, board, cur);
        dfs(row, col - 1, board, cur);
        board[row][col] = v;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        root->leaf = false;
        for (auto w: words) {
            insertWord(w);
        }
        
        nrows = board.size();
        ncols = board[0].size();
        
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                TrieNode* cur = root;
                dfs(row, col, board, cur);
            }
        }
        
        return vector<string>(found.begin(), found.end());  
    }
};

struct TrieNode {
    bool leaf;
    string word;
    map<char, TrieNode*> children;
};


class Solution {
public:
    TrieNode *root;
    int nrows;
    int ncols;
    set<string> found;
    
    void dfs(int row, int col, vector<vector<char>>& board, TrieNode* cur) {
        if (row < 0 || row >= nrows || col < 0 || col >= ncols) {
            return;
        }
        
        char v = board[row][col];
        if (cur->children.count(v) == 0) {
            return;
        }
        cur = cur->children[v];
        board[row][col] = ' ';
        
        if (cur->leaf) {
            found.insert(cur->word);
        }
        
        dfs(row + 1, col, board, cur);
        dfs(row - 1, col, board, cur);
        dfs(row, col - 1, board, cur);
        dfs(row, col + 1, board, cur);
        
        board[row][col] = v;
    }
    
    void insertWord(string& w) {
        TrieNode *p = root;
        for (auto c: w) {
            if (p->children.count(c) == 0) {
                p->children[c] = new TrieNode();
                p->children[c]->leaf = false;
            }
            p = p->children[c];
        }
        p->leaf = true;
        p->word = w;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        root->leaf = false;
        for (auto w: words) {
            insertWord(w);
        }
        nrows = board.size();
        ncols = board[0].size();
        
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                dfs(row, col, board, root);
            }
        }
        
        return vector<string>(found.begin(), found.end());
    }
};

 struct TrieNode {
    bool is_word;
    map<char, TrieNode*> children;
};

class Solution {
public:
    int nrows;
    int ncols;
    set<string> found;
    
    void dfs(vector<vector<char>>& board, TrieNode* p, int row, int col, string& curWord) {
        if (row < 0 || row >= nrows || col < 0 || col >= ncols) {
            return;
        }
        
        char c = board[row][col];
        if (p->children.count(c) == 0) {
            return;
        }
        
        p = p->children[c];
        curWord.push_back(c);
        board[row][col] = ' ';
        
        if (p->is_word) {
            found.insert(curWord);
        }
        
        dfs(board, p, row + 1, col, curWord);
        dfs(board, p, row - 1, col, curWord);
        dfs(board, p, row, col + 1, curWord);
        dfs(board, p, row, col - 1, curWord);
        
        board[row][col] = c;
        curWord.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        root->is_word = false;
        for (auto word: words) {
            TrieNode *p = root;
            for (char c: word) {
                if (p->children.count(c) == 0) {
                    p->children[c] = new TrieNode();
                    p->children[c]->is_word = false;
                }
                p = p->children[c];
            }
            p->is_word = true;
        }
        
        nrows = board.size();
        ncols = board[0].size();
        
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                string curWord;
                dfs(board, root, row, col, curWord);
            }
        }
        
        return vector<string>(found.begin(), found.end());
    }
};

struct TrieNode {
    bool isWord;
    map<char, TrieNode*> children;
};

class Solution {
public:
    int nrows;
    int ncols;
    
    void dfs(int row, int col, TrieNode* p, vector<vector<char>>& board, set<string>& found, string& s) {
        if (row < 0 || row >= nrows || col < 0 || col >= ncols) {
            return;
        }
        char c = board[row][col];
        p = p->children[c];
        
        if (!p) {
            return;            
        }
        
        board[row][col] = ' ';
        s.push_back(c);
        if (p->isWord) {
            found.insert(s);
        }
        
        dfs(row + 1, col, p, board, found, s);
        dfs(row - 1, col, p, board, found, s);
        dfs(row, col + 1, p, board, found, s);
        dfs(row, col - 1, p, board, found, s);

        board[row][col] = c;
        s.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        root->isWord = false;
        
        for (auto w: words) {
            TrieNode *p = root;
            for (auto c: w) {
                if (p->children.count(c) == 0) {
                    p->children[c] = new TrieNode();
                    p->children[c]->isWord = false;
                }
                p = p->children[c];
            }
            p->isWord = true;
        }
        
        nrows = board.size();
        ncols = board[0].size();
        
        set<string> found;
        
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                string s;
                dfs(row, col, root, board, found, s);
            }
        }
        
        return vector<string>(found.begin(), found.end());
    }
};


struct TrieNode {
    map<char, TrieNode*> children;
    bool isLeaf;
    string word;
    TrieNode() {
        isLeaf = false;
    }
};

class Solution {
public:
    void addWord(TrieNode* root, string& w) {
        TrieNode *p = root;
        for (auto c: w) {
            if ((p->children).count(c) == 0) {
                p->children[c] = new TrieNode();
            }
            p = p->children[c];
        }
        p->isLeaf = true;
        p->word = w;
    }
    
    void r(vector<vector<char>>& board, TrieNode* p, set<string>& found, int row, int col) {
        if (p->isLeaf) {
            found.insert(p->word);
        }
        
        int nrows = board.size();
        int ncols = board[0].size();
        if (row < 0 || row >= nrows || col < 0 || col >= ncols) {
            return;
        }
        

        char c = board[row][col];
        if (p->children.count(c) == 0) {
            return;
        }

        p = p->children[c];
        board[row][col] = '.';
        r(board, p, found, row + 1, col);
        r(board, p, found, row - 1, col);
        r(board, p, found, row, col + 1);
        r(board, p, found, row, col - 1);
        board[row][col] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (auto w: words) {
            addWord(root, w);
        }
        
        int nrows = board.size();
        int ncols = nrows > 0 ? board[0].size() : 0;
        
        set<string> found;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                r(board, root, found, row, col);
            }
        }
        
        return vector<string>(found.begin(), found.end());
    }
};

struct TrieNode {
    bool isWord;
    map<char, TrieNode*> children;
    TrieNode() {
        isWord = false;
    }
};

void addWord(TrieNode *root, string& w) {
    TrieNode *p = root;
    for (char c: w) {
        if (p->children.count(c) == 0) {
            p->children[c] = new TrieNode();
        }
        p = p->children[c];
    }
    p->isWord = true;
}

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* p, set<string>& S, string& cur) {
        char v = board[row][col];
        if (p->children.count(v) == 0) {
            return;
        }
        p = p->children[v];

        cur.push_back(v);
        board[row][col] = '.';
        if (p->isWord) {
            S.insert(cur);
        }

        int nrows = board.size();
        int ncols = nrows > 0 ? board[0].size() : 0;
        
        vector<int> dr{1, -1, 0, 0};
        vector<int> dc{0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int r = row + dr[i];
            int c = col + dc[i];
            if (r >= 0 && r < nrows && c >= 0 && c < ncols) {
                dfs(board, r, c, p, S, cur);
            }
        }
        
        board[row][col] = v;
        cur.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (auto w: words) {
            addWord(root, w);
        }
        
        int nrows = board.size();
        int ncols = nrows > 0 ? board[0].size() : 0;
        set<string> S;
        string cur;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                dfs(board, row, col, root, S, cur);
            }
        }
        
        vector<string> V(S.begin(), S.end());
        return V;
    }
};
