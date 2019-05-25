class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        for (int i = 1; i < n - 1; i++) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int lo = 1;
        int hi = n - 2;
        int best = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] > A[mid - 1]) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
        
    }
};
