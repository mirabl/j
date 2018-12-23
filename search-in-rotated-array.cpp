class Solution {
public:
    int p(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (nums[lo] > nums[hi]) {
            int mid = lo + (hi - lo) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return mid;
            }
            if (nums[mid] >= nums[lo]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    int binarySearch(vector<int>& nums, int target, int lo, int hi) {
        if (lo >= hi) {
            return nums[lo] == target ? lo : -1;
        }
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, hi);
        } else if (nums[mid] > target) {
            return binarySearch(nums, target, lo, mid - 1);
        } else {
            return mid;
        }
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int pivot = p(nums);
        if (pivot == 0 || target < nums[0]) {
            return binarySearch(nums, target, pivot, nums.size() - 1);
        } else {
            return binarySearch(nums, target, 0, pivot - 1);
        }
        
    }
};

// https://discuss.leetcode.com/topic/34491/clever-idea-making-it-simple/2

class Solution {
public:
    int findMax(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int n = nums.size();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == n - 1 || nums[mid + 1] < nums[mid]) {
                return mid;
            }
            if (nums[mid] >= nums[0]) {
                lo = mid + 1;
            } else if (nums[mid] < nums[0]) {
                hi = mid - 1;
            }
        }
        return -1;
    }
    
    int bs(vector<int>& nums, int target, int lo, int hi) {
        if (hi <= lo) {
            return nums[hi] == target ? hi : -1;
        }
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return bs(nums, target, mid + 1, hi);
        } else {
            return bs(nums, target, lo, mid - 1);
        }
        
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int iMax = findMax(nums);
        if (target >= nums[0]) {
            return bs(nums, target, 0, iMax);
        } else {
            return bs(nums, target, iMax + 1, nums.size() - 1);
        }
    }
};


class Solution {
public:
    int fm(vector<int>& A) {
        int n = A.size();
        if (A[0] <= A[n - 1]) {
            return 0;
        }
        int lo = 1;
        int hi = n - 1;
        while (true) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid - 1] > A[mid]) {
                return mid;
            }
            if (A[mid] > A[0]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1; // NR
    }
    
    int bs(vector<int>& A, int y, int lo, int hi) {
        if (hi < lo) {
            return -1;
        }
        int mid = lo + (hi - lo) / 2;
        if (A[mid] == y) {
            return mid;
        }
        if (A[mid] < y) {
            return bs(A, y, mid + 1, hi);
        } else {
            return bs(A, y, lo, mid - 1);
        }
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int imin = fm(nums);
        if (imin == 0) {
            return bs(nums, target, 0, int(nums.size()) - 1);
        } 
        
        if (target >= nums[0]) {
            return bs(nums, target, 0, imin - 1);
        } else {
            return bs(nums, target, imin, int(nums.size()) - 1);
        }
    }
};
