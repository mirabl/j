class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int S = accumulate(nums.begin(), nums.end(), 0);
        if (S % 2 != 0) {
            return false;
        }
        int T = S / 2;
        vector<int> M(T + 1, 0);
        M[0] = 1;
        for (int x: nums) {
            for (int i = T; i >= x; i--) {
                M[i] |= M[i - x];
            }
        }
        return M[T] != 0;
    }
};