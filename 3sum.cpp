class Solution {
public:
    void findPairWithSum(vector<int>& nums, int T, int lo, vector<vector<int>>& res) {
        int hi = nums.size() - 1;
        while (lo != hi) {
            if (nums[lo] + nums[hi] == T) {
                res.push_back({- T, nums[lo], nums[hi]});
            }
            if (nums[lo] + nums[hi] <= T) {
                do {
                    lo++;
                } while (lo != hi && nums[lo] == nums[lo - 1]);
            } else {
                hi--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            findPairWithSum(nums, - nums[i], i + 1, res);
        }
        return res;
    }
};