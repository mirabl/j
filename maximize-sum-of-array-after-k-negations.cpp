class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        
        int n = A.size();
        int i = 0;
        while (K > 0 && i < n && A[i] <= 0) {
            A[i] = - A[i];
            i++;
            K--;
        }
        
        sort(A.begin(), A.end());
        
        if (K % 2 == 1) {
            A[0] = - A[0];
        }
        
        int res = 0;
        for (auto x: A) {
            res += x;
        }
        return res;
    }
};
