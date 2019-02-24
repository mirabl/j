class Solution {
public:
    int countTriplets(vector<int>& A) {
        int M = 1 << 16;
        vector<int> L(M);
        for (int m = 0; m < M; m++) {
            for (auto x: A) {
                if ((x & m) == 0) {
                    L[m]++;
                }
            }
        }
        
        int n = A.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += L[A[i] & A[j]];
            }
        }
        return res;
    }
};
