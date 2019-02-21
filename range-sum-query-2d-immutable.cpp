class NumMatrix {
public:
    vector<vector<int>> S;
    
    NumMatrix(vector<vector<int>> matrix) {
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        
        S = vector<vector<int>>(n, vector<int>(m, 0));
        
        for (int row = 0; row < n; row++) {
            int t = 0;
            for (int col = 0; col < m; col++) {
                t += matrix[row][col];
                S[row][col] = (row > 0 ? S[row - 1][col] : 0) + t;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = S[row2][col2] - (row1 > 0 ? S[row1 - 1][col2] : 0) - (col1 > 0 ? S[row2][col1 - 1] : 0) \
            + (row1 > 0 && col1 > 0 ? S[row1 - 1][col1 - 1] : 0);
        
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

