/*
https://leetcode.com/problems/unique-paths/
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int A[m][n];
        A[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                A[i][j] = 0;
                if (i - 1 >= 0) {
                    A[i][j] += A[i - 1][j];
                }
                if (j - 1 >= 0) {
                    A[i][j] += A[i][j - 1];
                }
            }
        }
        return A[m - 1][n - 1];
    }
};