class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        vector<int> Z;
        int n = A.size();
        Z.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                Z.push_back(i);
            }
        }
        K = min(K, int(Z.size()) - 1);
        Z.push_back(n);
        int m = Z.size();
        
        int res = 0;
        for (int i = 1; i < m - K; i++) {
        //    cout << "i=" << i << endl;
         //  cout << "  " << Z[i + 1] << ", " << Z[i - 1] << endl;
            int l = Z[i + K] - 1 - (Z[i - 1] + 1) + 1;
            res = max(res, l);
        }
        
        return res;
        
    }
};
