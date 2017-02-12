class Solution {
public:
    int numTrees(int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> A(n + 1, 0);
        A[0] = 1;
        A[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                A[i] += A[j - 1] * A[i - j];
            }
        }
        return A[n];
    }
};