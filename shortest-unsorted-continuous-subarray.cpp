class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> maxBefore(n, nums.front());
        vector<int> minAfter(n, nums.back());
        
        for (int i = 1; i < n; i++) {
            maxBefore[i] = max(maxBefore[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            minAfter[i] = min(minAfter[i + 1], nums[i]);
        }
        
        int r = n - 1;
        while (r > 0 && nums[r] >= maxBefore[r - 1]) {
            r--;
        }
        
        int l = 0;
        while (l <= r && nums[l] <= minAfter[l + 1]) {
            l++;
        }
        return r - l + 1;
    }
};

// better O(1) space
// https://discuss.leetcode.com/topic/89322/c-o-n-solution