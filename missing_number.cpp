class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = int(nums.size()) + 1;
        vector<int> A(n, 1);
        int res = 0;
        for (int x: nums) {
            A[x] = 0;
            while (res < n - 1 && A[res] == 0) {
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = int(nums.size());
        for (int x: nums) {
            if (x < 0) {
                x = - x - 1;
            }
            if (x == n) {
                continue;
            }
            nums[x] = - 1 - nums[x];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                return i;
            }
        }
        return n;
    }
};

