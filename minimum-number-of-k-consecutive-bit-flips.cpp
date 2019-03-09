class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int res = 0;
        for (int i = 0; i < n - K + 1; i++) {
            // cout <<"i=" << i << endl;
            if (A[i] == 0) {
               // cout << "flip: i=" << i << endl;
                res++;
                for (int j = i; j < i + K && j < n; j++) {
                    A[j] = 1 - A[j];
                }
            }
        }
        
        for (int i = max(n - K - 1, 0); i < n; i++) {
            if (A[i] == 0) {
                return -1;
            }
        }
        return res;
    }
};
