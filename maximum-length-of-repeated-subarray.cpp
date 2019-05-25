maximum-length-of-repeated-subarray
class Solution {
public:
    int f(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        
        int best = 0;
        for (int o = 0; o < n; o++) {
            int cur = 0;
            for (int i = 0; i < n - o && i < m; i++) {
                if (A[i + o] == B[i]) {
                    cur++;
                    best = max(best, cur);
                } else {
                    cur = 0;
                }
            }
        }
        return best;
    }

    int findLength(vector<int>& A, vector<int>& B) {
        return max(f(A, B), f(B, A));
    }
    
};

class Solution {
public:
    int get(vector<vector<int>>& T, int i, int j) {
        return i >= 0 && j >= 0 ? T[i][j] : 0;
    }
    
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> T(n, vector<int>(m));
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] == B[j]) {
                    T[i][j] = 1 + get(T, i - 1, j - 1);
                    best = max(best, T[i][j]);
                }
            }
        }
        return best;
    }
};

class Solution {
public:
    int get(vector<vector<int>>& T, int i, int j) {
        return i >= 0 && j >= 0 ? T[i][j] : 0;
    }
    
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<int> T(m);
        vector<int> U(m);
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] == B[j]) {
                    U[j] = 1 + (j - 1 >= 0 ? T[j - 1] : 0);
                    best = max(best, U[j]);
                } else {
                    U[j] = 0;
                }
            }
            swap(T, U);
        }
        return best;
    }
};
