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

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int N = nums.size();
        int lo = 0;
        int hi = N - 1;
        while (lo != hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[N - 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (target <= nums[N - 1]) {
            hi = N - 1;
        } else {
            lo = 0;
            hi--;
        }

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return -1;
    }
};



class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int N = nums.size();
        int lo = 0;
        int hi = N - 1;
        while (lo != hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[N - 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if (nums[0] <= nums[N - 1]) {
            lo = 0;
            hi = N - 1;
        } else if (target >= nums[0]) {
            lo = 0;
            hi = max(0, hi - 1);
        } else {
            lo = hi;
            hi = N - 1;
        }
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int N = nums.size();
        int lo = 0;
        int hi = N - 1;
        while (lo != hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[N - 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if (target <= nums[N - 1]) {
            hi = N - 1;
        } else {
            lo = 0;
            hi = hi - 1;
        }
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int fm(vector<int>& nums) {
        int lo = 0;
        int hi = int(nums.size()) - 1;
        int n = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[n - 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    int bs(vector<int>& nums, int t, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == t) {
                return mid;
            } else if (nums[mid] > t) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            } 
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int minI = fm(nums);
        int n = nums.size();
        if (target > nums[n - 1]) {
            return bs(nums, target, 0, minI - 1);
        } else {
            return bs(nums, target, minI, n - 1);
        }
    }
};


class Solution {
public:
    int fm(vector<int>& A) {
        int n = A.size();
        int lo = 0;
        int hi = n - 1;
        int best = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] <= A[n - 1]) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return best;
    }
    
    int bs(vector<int>& A, int x, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == x) {
                return mid;
            } else if (A[mid] > x) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        
        int iMin = fm(nums);
        if (target > nums[nums.size() - 1]) {
            return bs(nums, target, 0, iMin - 1);
        } else {
            return bs(nums, target, iMin, nums.size() - 1);
        }
    }
};
