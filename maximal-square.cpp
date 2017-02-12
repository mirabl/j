class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int nrows = int(matrix.size());
        const int ncols = matrix.empty() ? 0 : int(matrix[0].size());
        vector<vector<int>> A(nrows, vector<int>(ncols, 0));
        int m = 0;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (matrix[row][col] == '1') {
                    A[row][col] = 1;
                    if (row > 0 && col > 0) {
                        for (int w = 1; w <= A[row - 1][col - 1] && matrix[row][col - w] == '1' && matrix[row - w][col] == '1'; w++) {
                           A[row][col]++;
                        }
                    }
                }
                m = max(m, A[row][col]);
            }
        }
        return m * m;
    }
};



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int nrows = int(matrix.size());
        const int ncols = matrix.empty() ? 0 : int(matrix[0].size());
        vector<vector<int>> A(nrows, vector<int>(ncols, 0));
        int m = 0;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (matrix[row][col] == '1') {
                    A[row][col] = 1;
                    if (row > 0 && col > 0) {
                        A[row][col] += min(A[row - 1][col - 1], min(A[row - 1][col], A[row][col - 1]));
                    }
                }
                m = max(m, A[row][col]);
            }
        }
        return m * m;
    }
};


