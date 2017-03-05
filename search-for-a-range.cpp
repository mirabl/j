class Solution {
public:

    int bsLow(vector<int>& A, int T) {
        int lo = 0;
        int hi = A.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == T && (mid == 0 || A[mid - 1] < T)) {
                return mid;
            } else if (A[mid] >= T) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
    
    int bsHi(vector<int>& A, int T) {
        int lo = 0;
        int hi = A.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == T && (mid == A.size() - 1 || A[mid + 1] > T)) {
                return mid;
            } else if (A[mid] <= T) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) { 
            return {-1, -1};
        }
        int lo = bsLow(nums, target);
        int hi = bsHi(nums, target);
        return {lo, hi};
    }
};


// https://discuss.leetcode.com/topic/6327/a-very-simple-java-solution-with-only-one-binary-search-algorithm
class Solution {
public:

    int bsLow(vector<int>& A, int T) {
        int lo = 0;
        int hi = A.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] < T) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) { 
            return {-1, -1};
        }
        int lo = bsLow(nums, target);
        if (lo == nums.size() || nums[lo] != target) {
            return {-1, -1};
        }
        int hi = bsLow(nums, target + 1) - 1;
        return {lo, hi};
    }
};