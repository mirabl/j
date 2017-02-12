class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> A(n, vector<int>(n, 1));
        int c = 1;
        for (int k = 0; k < (n + 1) / 2; k++) {
            A[k][k] = c++;
            for (int col = k + 1; col < n - k - 1; col++) {
                A[k][col] = c++;
            }
            for (int row = k; row < n - k - 1; row++) {
                A[row][n - 1 - k] = c++;
            }
            for (int col = n - 1 - k; col > k; col--) {
                A[n - 1 - k][col] = c++;
            }
            for (int row = n - 1 - k; row > k; row--) {
                A[row][k] = c++;
            }
        }
        return A;
    }
};

