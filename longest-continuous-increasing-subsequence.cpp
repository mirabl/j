class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int best = 0;
        int current = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                current++;
            } else {
                current = 1;
            }
            best = max(best, current);
        }
        return best;
    }
};