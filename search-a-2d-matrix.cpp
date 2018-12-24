class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int num_rows = int(matrix.size());
        int num_cols = int(matrix[0].size());
        
        if (target < matrix[0][0] || target > matrix[num_rows - 1][num_cols - 1]) {
            return false;
        }
        int row = 0;
        while (row < num_rows - 1 && matrix[row + 1][0] <= target) {
            row++;
        }
        for (int col = 0; col < num_cols; col++) {
            if (matrix[row][col] == target) {
                return true;
            }
        }
        return false;
    }
};


// Better: BS on whole matrix, not rows then columns