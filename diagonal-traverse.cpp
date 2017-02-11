class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        const int nrows = int(matrix.size());
        const int ncols = int(matrix[0].size());
        int drow = -1;
        int dcol = 1;
        int row = 0;
        int col = 0;
        for (int k = 0; k < nrows + ncols - 1; k++) {
            if (k % 2 == 0) {
                row = min(k, nrows - 1);
                col = k - row;
            } else {
                col = min(k, ncols - 1);
                row = k - col;
            }
            while (row >= 0 && row < nrows && col >= 0 && col < ncols) {
                res.push_back(matrix[row][col]);
                row += drow;
                col += dcol;
            }
            swap(drow, dcol);
        }
        return res;
    }
};