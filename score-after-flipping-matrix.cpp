class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int res = 0;
        for (int row = 0; row < A.size(); row++) {
            if (A[row][0] == 0) {
                for (int col = 0; col < A[row].size(); col++) {
                    A[row][col] ^= 1;
                }
            }
        }
        
        for (int col = 1; col < A[0].size(); col++) {
            int numOne = 0;
            for (int row = 0; row < A.size(); row++) {
                numOne += A[row][col];
            }
            if (numOne <= A.size() / 2) {
                for (int row = 0; row < A.size(); row++) {
                    A[row][col] ^= 1;
                }
            }
        }

        for (int row = 0; row < A.size(); row++) {
            int r = 0;
            for (int col = 0; col < A[0].size(); col++) {
                r = 2 * r + A[row][col];
            }
            res += r;
        }
        
        return res;
    }
};
