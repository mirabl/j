/*
https://leetcode.com/problems/maximum-subarray/
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
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
};