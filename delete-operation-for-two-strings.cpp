class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> M(n + 1, vector<int>(m + 1));
        for (int col = 0; col <= m; col++) {
            M[0][col] = col;
        }
        for (int row = 1; row <= n; row++) {
            M[row][0] = row;
        }
        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= m; col++) {
                if (word1[row - 1] == word2[col - 1]) {
                    M[row][col] = M[row - 1][col - 1];
                } else {
                    M[row][col] = 1 + min(M[row - 1][col], M[row][col - 1]);
                }
            }
        }
        return M[n][m];
    }
};

class Solution {
public:
    int get(vector<vector<int>>& T, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        return T[i][j];
    }
    
    int lcs(string& s, string& t) {
        if (s.empty() || t.empty()) {
            return 0;
        }
        
        int n = s.size();
        int m = t.size();
        vector<vector<int>> T(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j]) {
                    T[i][j] = 1 + get(T, i - 1, j - 1);
                } else {
                    T[i][j] = max(get(T, i - 1, j), get(T, i, j - 1));
                }
            }
        }
        return T[n - 1][m - 1];
    }
    
    int minDistance(string word1, string word2) {
        int l = lcs(word1, word2);
        return word1.size() - l + word2.size() - l;
    }
};

class Solution {
public:
    int get(vector<vector<int>>& T, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        return T[i][j];
    }
    
    int lcs(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        
        if (s.empty() || t.empty()) { 
            return 0;
        }
        
        vector<vector<int>> T(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                T[i][j] = max(max(get(T, i - 1, j - 1) + (s[i] == t[j] ? 1 : 0),
                             get(T, i - 1, j)), get(T, i, j - 1));
            }
        }
        return T[n - 1][m - 1];
    }
    
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * lcs(word1, word2);
    }
};
