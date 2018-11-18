class Solution {
public:
    bool validMountainArray(vector<int>& A) {    
        int iMax = 0;
        int n = A.size();
        if (n < 3) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (A[i] > A[iMax]) {
                iMax = i;
            }
        }
        if (iMax == 0 || iMax == n - 1) {
            return false;
        }
        for (int i = 0; i < iMax; i++) {
            if (A[i] >= A[i + 1]) {
                return false;
            }
        }
        for (int i = iMax; i < n - 1; i++) {
            if (A[i] <= A[i + 1]) {
                return false;
            }
        }
        return true;        
    }
};
