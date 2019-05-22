class Solution {
public:
    int n;
    int m;
    
    map<pair<int, int>, int> F;
    
    int r(vector<int>& A, int i, vector<int>& B, int j) {
        if (F.count({i, j}) == 1) {
            return F[{i, j}];
        }
        if (i >= n || j >= m) {
            return 0;
        }
        
        if (A[i] == B[j]) {
            F[{i, j}] = 1 + r(A, i + 1, B, j + 1);
        } else {
            F[{i, j}] = max(r(A, i + 1, B, j), r(A, i, B, j + 1));
        }
        
        return F[{i, j}];
        
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        n = A.size();
        m = B.size();
        return r(A, 0, B, 0);
    }
};
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        
        vector<vector<int>> T(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (A[i] == B[j]) {
                    T[i][j] = 1 + T[i + 1][j + 1];
                } else {
                    T[i][j] = max(T[i + 1][j], T[i][j + 1]);
                }
            }
        }
        return T[0][0];
        
    }
};
