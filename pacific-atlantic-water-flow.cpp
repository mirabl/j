/* TODO: cleanup */

class Solution {
public:

    void mark_rec(int row, int col, vector<vector<int>>& A, vector<vector<int>>& matrix) {
    int REACHABLE = 1;
        int n = int(matrix.size());
        int m = int(matrix[0].size());
        if (row < 0 || row >= n || col < 0 || col >= m || A[row][col] == REACHABLE) {
            return;
        }
        
        A[row][col] = REACHABLE;
        int dr[4] = { -1, 1,  0, 0 };
        int dc[4] = {  0, 0, -1, 1 };
        for (int i = 0; i  < 4; i++) {
            if ((!(row + dr[i] < 0 || row + dr[i] >= n || col + dc[i] < 0 || col + dc[i] >= m)) 
            && matrix[row + dr[i]][col + dc[i]] >= matrix[row][col]) {
                mark_rec(row + dr[i], col + dc[i], A, matrix);
            }
        }
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    int REACHABLE = 1;
        int n = int(matrix.size());
        if (n == 0) {
            return vector<pair<int, int>>();
        }
        int m = int(matrix[0].size());
        vector<vector<int>> A(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            mark_rec(row, 0, A, matrix);
        }
        for (int col = 0; col < m; col++) {
            mark_rec(0, col, A, matrix);
        }
        vector<vector<int>> B(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            mark_rec(row, m - 1, B, matrix);
        }
        for (int col = 0; col < m; col++) {
            mark_rec(n - 1, col, B, matrix);
        }
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                cout << A[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                cout << B[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
                
       vector<pair<int, int>> res;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (A[row][col] == REACHABLE && B[row][col] == REACHABLE) {
                    res.push_back({row, col});
                }
           }
        }
            
        return res;
    }
};
