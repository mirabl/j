// https://leetcode.com/problems/largest-plus-sign/description/
class Solution {
public:
    
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        
        vector<vector<int>> up(N, vector<int>(N, 0));
        vector<vector<int>> down(N, vector<int>(N, 0));
        vector<vector<int>> left(N, vector<int>(N, 0));
        vector<vector<int>> right(N, vector<int>(N, 0));
       
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                down[row][col] = N - row;
                up[row][col] = row + 1;
                left[row][col] = col + 1;
                right[row][col] = N - col;
            }
        }        
        
        for (auto mine: mines) {
            int rm = mine[0];
            int cm = mine[1];
            
            for (int row = rm; row >= 0; row--) {
                down[row][cm] = min(down[row][cm], rm - row);
            }
            for (int row = rm; row < N; row++) {
                up[row][cm] = min(up[row][cm], row - rm);
            }
            for (int col = cm; col >= 0; col--) {
                right[rm][col] = min(right[rm][col], cm - col);
            }
            for (int col = cm; col < N; col++) {
                left[rm][col] = min(left[rm][col], col - cm);
            }
        }
        
        int res = 0;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                res = max(res, min(up[row][col], min(down[row][col], min(right[row][col], left[row][col]))));
            }
        }
        
        return res;   
    }
};
