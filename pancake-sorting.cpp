class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        int n = A.size();
        for (int j = n - 1; j >= 0; j--) {
            int iMax = 0;
            for (int i = 1; i <= j; i++) {
                if (A[i] > A[iMax]) {
                    iMax = i;
                }
            }
            res.push_back(iMax + 1);
            for (int k = 0; k <= iMax / 2; k++) {
                swap(A[k], A[iMax - k]);
            }
            res.push_back(j + 1);
            for (int k = 0; k <= j / 2; k++) {
                swap(A[k], A[j - k]);
            }
        }
        return res;
    }
};
