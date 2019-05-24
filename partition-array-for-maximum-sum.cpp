class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        int infty = 1e8;
        vector<int> T(n, - infty);
        T[0] = A[0];
        for (int i = 1; i < n; i++) {
            int w = - infty;
            for (int l = 1; l <= K && l <= i + 1; l++) {
                w = max(w, A[i - l + 1]);
                T[i] = max(T[i], w * l + (i - l >= 0 ? T[i - l] : 0));
            }
        }
        return T.back();
    }
};
