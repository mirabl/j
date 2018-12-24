/*
https://leetcode.com/problems/house-robber-ii/
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = int(nums.size());
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        }
        vector<int> Mw0(n);
        vector<int> Mn0(n);
        Mw0[0] = nums[0];
        Mw0[1] = max(nums[0], nums[1]);
        Mn0[0] = 0;
        Mn0[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            Mw0[i] = max(Mw0[i - 1], nums[i] + Mw0[i - 2]);
            Mn0[i] = max(Mn0[i - 1], nums[i] + Mn0[i - 2]);
        }
        return max(Mw0[n - 2], Mn0[n - 1]);
    }
};