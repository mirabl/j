/*
https://leetcode.com/problems/perfect-squares/
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> A(n + 1, -1);
        A[0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            for (int y = 1; y*y < i + 1; ++y) {
                if (A[i] == -1) {
                    A[i] = 1 + A[i - y*y];
                } else {
                    A[i] = min(A[i], 1 + A[i - y*y]);
                }
            }
        }
        return A[n];
    }
};