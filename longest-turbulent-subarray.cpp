class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        
        vector<int> U(n);
        vector<int> D(n);
        U[0] = 1;
        D[0] = 1;
        
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                U[i] = D[i - 1] + 1;
                D[i] = 1;
            } else if (A[i] < A[i - 1]) {
                U[i] = 1;
                D[i] = U[i - 1] + 1;
            } else {
                U[i] = 1;
                D[i] = 1;
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, D[i]);
            res = max(res, U[i]);
        }
        return res;
    }
};
