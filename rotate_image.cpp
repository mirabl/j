/*
https://leetcode.com/problems/rotate-image/
*/

// or 
// https://discuss.leetcode.com/topic/6796/a-common-method-to-rotate-the-image
// reverse up to down then transpose

class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        int n = int(A.size());
        for (int k = 0; k < int(n / 2); ++k) {
            
            for (int i = 0; i < n - 2 * k - 1; ++i) {
                int tmp = A[k][k + i];
                A[k][k + i] = A[n - 1 - (k + i)][k];
                A[n - 1 - (k + i)][k] = A[n - 1 - k][n - 1 - (k + i)];
                A[n - 1 - k][n - 1 - (k + i)] = A[k + i][n - 1 - k];
                A[k + i][n - 1 - k] = tmp;
            }
        }
    }
};