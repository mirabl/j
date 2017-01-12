/*
https://leetcode.com/problems/triangle/
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = int(triangle.size());
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return triangle[0][0];
        }
        int M[n][n];
        M[0][0] = triangle[0][0];
        for (int r = 1; r < n; r++) {
            M[r][0] = M[r - 1][0] + triangle[r][0];
            M[r][r] = M[r - 1][r - 1] + triangle[r][r];
            for (int c = 1; c < r; c++) {
                M[r][c] = triangle[r][c] + min(M[r - 1][c - 1], M[r - 1][c]);
            }
        }
        int m = M[n - 1][0];
        for (int c = 1; c < n + 1; ++c) {
            m = min(m, M[n - 1][c]);
        }
        return m;
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = int(triangle.size());
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return triangle[0][0];
        }
        vector<int> prev(n);
        vector<int> cur(n);
        prev[0] = triangle[0][0];
        for (int r = 1; r < n; r++) {
            cur[0] = prev[0] + triangle[r][0];
            cur[r] = prev[r - 1] + triangle[r][r];
            for (int c = 1; c < r; c++) {
                cur[c] = triangle[r][c] + min(prev[c - 1], prev[c]);
            }
            swap(prev, cur);
        }
        int m = prev[0];
        for (int c = 1; c < n + 1; ++c) {
            m = min(m, prev[c]);
        }
        return m;
    }
};