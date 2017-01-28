class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int cur = nums[0];
        int m = cur;
        for (int i = 1; i < int(nums.size()); i++) {
            if (nums[i] == 1) {
                cur++;
            } else {
                cur = 0;
            }   
            m = max(m, cur);
        }
        return m;
    }
};