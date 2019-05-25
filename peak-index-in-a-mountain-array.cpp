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
class Solution {
public:
    int r(vector<int>& A, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
            return mid;
        }
        if (A[mid] < A[mid + 1]) {
            return r(A, mid + 1, hi);
        } else {
            return r(A, lo, mid - 1);
        }
    }
    
    int peakIndexInMountainArray(vector<int>& A) {
        return r(A, 1, int(A.size()) - 2);
    }
};
