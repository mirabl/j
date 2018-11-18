class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            bool remove = false;
            for (int j = 0; j < n - 1; j++) {
                if (A[j][i] > A[j + 1][i]) {
                    remove = true;
                }
            }
            if (remove) {
                res++;
            }
        }
        return res;
    }
};
