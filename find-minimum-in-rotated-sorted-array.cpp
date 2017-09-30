class Solution {
public:
    int findMin(vector<int>& A) {
        if (A.front() <= A.back()) {
            return A.front();
        }
        int lo = 0;
        int hi = A.size() - 1;
        while (A[lo] > A[lo - 1]) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] >= A[lo]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return A[lo];
    }
};