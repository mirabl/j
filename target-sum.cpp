class Solution {
public:
    map<pair<int, int>, int> M;

    int rec(vector<int>& nums, int S, int offset) {
        if (offset == int(nums.size())) {
            return S == 0 ? 1 : 0;
        }
        if (M.count({S, offset}) == 0) {
             M[{S, offset}] = rec(nums, S - nums[offset], offset + 1) + rec(nums, S + nums[offset], offset + 1);
        }
        return M[{S, offset}];
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        return rec(nums, S, 0);
    }
};