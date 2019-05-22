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
