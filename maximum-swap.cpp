class Solution {
public:
    int maximumSwap(int num) {
        int x = num;
        vector<int> A;
        while (x != 0) {
            A.push_back(x % 10);
            x /= 10;
        }
        reverse(A.begin(), A.end());
        int n = A.size();
        for (int i = 0; i < n - 1; i++) {
            int iMax = i + 1;
            for (int j = i + 2; j < n; j++) {
                if (A[j] >= A[iMax]) {
                    iMax = j;
                }
            }
            if (A[iMax] > A[i]) {
                swap(A[iMax], A[i]);
                int res = 0;
                for (int j = 0; j < n; j++) {
                    res = res * 10 + A[j];
                }
                return res;
            }
        }
        
        return num;
    }
};
