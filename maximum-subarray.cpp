/*
https://leetcode.com/problems/maximum-subarray/
*/
class Solution {
public:
    int maxSubArray2(vector<int>& nums) {
        int n = int(nums.size());
        int MSE[n];
        int m;
        for (int i = 0; i < n; i++) {
            MSE[i] = nums[i];
            if (i > 0 && MSE[i - 1] > 0) {
                MSE[i] += MSE[i - 1];
            }
            if (i == 0 || MSE[i] > m) {
                m = MSE[i];
            }
        }
        return m;
    }
    
    // Inefficient.
    int maxSubArrayRec(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[start];
        }
        int mid = (start + end + 1) / 2;
        int res = max(maxSubArrayRec(nums, start, mid - 1), maxSubArrayRec(nums, mid, end));

        int m1 = 0;
        int s = 0;
        bool consider_middle = false;
        for (int i = mid; i <= end; i++) {
            s += nums[i];
            if (s > m1) {
                m1 = s;
                consider_middle = true;
            }
        }
        int m2 = 0;
        s = 0;
        for (int i = mid - 1; i >= start; i--) {
            s += nums[i];
            if (s > m2) {
                m2 = s;
                consider_middle = true;
            }
        }
        if (consider_middle) {
            res = max(res, m1 + m2);
        }
        return res;
    }
    
    int maxSubArray(vector<int>& nums) {
        int n = int(nums.size());
        if (n == 0) {
            return 0;
        }
        return maxSubArrayRec(nums, 0, n - 1);
    }
    
};