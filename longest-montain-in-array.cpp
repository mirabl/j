class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = int(A.size());
        vector<int> ldl(n, 0), ldr(n, 0);
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                ldl[i] = ldl[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1]) {
                ldr[i] = ldr[i + 1] + 1;
            }
        }
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (ldr[i] > 0 && ldl[i] > 0) {
                b = max(b, 1 + ldl[i] + ldr[i]);
            }
        }
        return b;
    }
};
