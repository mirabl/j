/*
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for (; i < int(nums.size()); i++) {
            if (nums[i] >= target) {
                break;
            }
        }
        return i;
    }
};


class Solution {
public:
    int search_rec(vector<int>& nums, int x, int lo, int hi) {
        if (lo == hi) {
            if (nums[lo] >= x) {
                return lo;
            } else {
                return lo + 1;
            }
        }
        int mid = lo + (hi - lo) / 2;
        if (x <= nums[mid]) {
            return search_rec(nums, x, lo, mid);
        } else {
            return search_rec(nums, x, mid + 1, hi);
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return search_rec(nums, target, 0, int(nums.size()) - 1);
    }
};


class Solution {
public:
    int search(vector<int>& nums, int x, int lo, int hi) {
        while (lo != hi) {
            int mid = lo + (hi - lo) / 2;
            if (x <= nums[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (nums[lo] >= x) {
            return lo;
        } else {
            return lo + 1;
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target, 0, int(nums.size()) - 1);
    }
};

class Solution {
public:
    int search(vector<int>& nums, int x, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (x == nums[mid]) {
                return mid;
            } else if (x < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target, 0, int(nums.size()) - 1);
    }
};