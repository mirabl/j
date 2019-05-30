class Solution {
public:
    int trap(vector<int>& A) {
        int n = A.size();
        vector<int> T(n);
        vector<int> U(n);
        
        for (int i = 0; i < n; i++) {
            T[i] = max(A[i], i > 0 ? T[i - 1] : 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            U[i] = max(A[i], i < n - 1 ? U[i + 1] : 0);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(U[i], T[i]) - A[i];
        }
        return res;
    }
};

