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

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 == 1) {
            return false;
        }
        int T = s / 2;
        vector<bool> A(T + 1);
        A[0] = true;
        
        for (int x: nums) {
            for (int y = T; y >= x; y--) {
                A[y] = A[y] || A[y - x];
            }
        }
        return A[T];
    }
};
