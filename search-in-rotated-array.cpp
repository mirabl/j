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

