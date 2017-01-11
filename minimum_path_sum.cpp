/*
https://leetcode.com/problems/minimum-path-sum/
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int num_rows = int(grid.size());
        int num_cols = int(grid[0].size());
        int A[num_rows][num_cols];
        
        A[0][0] = grid[0][0];
        for (int row = 1; row < num_rows; ++row) {
            A[row][0] = grid[row][0] + A[row - 1][0];
        }
        for (int col = 1; col < num_cols; ++col) {
            A[0][col] = grid[0][col] + A[0][col - 1];
        }
        for (int row = 1; row < num_rows; ++row) {
            for (int col = 1; col < num_cols; ++col) {
                A[row][col] = grid[row][col]+ min(A[row - 1][col], A[row][col - 1]);
            }
        }
        return A[num_rows - 1][num_cols - 1];
    }
};