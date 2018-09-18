class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < A.size() - 1; i++) {
            int d = A[i + 1] - A[i];
            if (d > 0) {
                pos++;
            } else if (d < 0) {
                neg--;
            }
        }
        return pos == 0 || neg == 0;
    }
};
