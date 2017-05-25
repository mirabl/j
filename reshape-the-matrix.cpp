class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r2 = nums.size();
        int c2 = nums.empty() ? 0 : nums[0].size();
        if (r * c != r2 * c2) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c));
        for (int k = 0; k < r * c; k++) {
            res[k / c][k % c] = nums[k / c2][k % c2];
        }
        return res;
    }
};