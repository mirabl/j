class Solution {
    int fm(int[] nums) {
        int lo = 0;
        int hi = nums.length - 1;
        int n = nums.length;
        int best = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= nums[n - 1]) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return best;
    }
    
    int bs(int[] nums, int lo, int hi, int target) {
        if (lo > hi) {
            return -1;
        }
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return bs(nums, mid + 1, hi, target);
        } else {
            return bs(nums, lo, mid - 1, target);
        }
    }
    
    public int search(int[] nums, int target) {
        int n = nums.length;
        if (n == 0) {
            return -1;
        }
        int im = fm(nums);
        System.out.println("im=" + im);
        if (target > nums[n - 1]) {
            return bs(nums, 0, im - 1, target);
        } else {
            return bs(nums, im, n - 1, target);
        }
    }
}

