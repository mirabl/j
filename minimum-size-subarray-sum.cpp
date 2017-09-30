class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        int l = n + 1;
        for (int i = 0; i < n; i++) {
            while (s > 0 && j < n) {
                s -= nums[j];
                j++;
            }
            if (s <= 0) {
                l = min(l, j - i);
            }
            s += nums[i];
        }
        return l != n + 1 ? l : 0;
    }
};