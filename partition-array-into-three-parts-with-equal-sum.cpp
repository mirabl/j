class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int totalSum = accumulate(A.begin(), A.end(), 0);
        int N = A.size();

        map<int, int> left;
        int c = 0;
        for (int i = 0; i < N; i++) {
            c += A[i];
            if (left.count(c) == 0) {
                left[c] = i;
            }
        }
        
        c = 0;
        for (int i = N - 1; i > 0; i--) {
            c += A[i];
            if (totalSum != 3 * c) {
                continue;
            }
            int y = c;
            if (left.count(y) == 1 && left[y] < i - 1) {
                return true;
            }
            
        }
        
        return false;
    }
};
