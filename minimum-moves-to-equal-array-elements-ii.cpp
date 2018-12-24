class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median;
        const int n = int(nums.size());
        if (n % 2 == 1) {
            median = nums[n / 2];
        } else {
            median = (nums[(n / 2) - 1] + nums[n / 2]) / 2;
        }
        int moves = 0;
        for (int x: nums) {
            moves += abs(median - x);
        }
        return moves;
    }
};