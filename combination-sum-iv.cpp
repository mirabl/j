class Solution {
public:
    map<int, int> memo;

    int combinationSum4(vector<int>& nums, int target) {
        if (target < 0 || nums.empty()) {
            return 0;
        } else if (target == 0) {
            return 1;
        }
        if (memo.count(target) == 0) {
            int c = 0;
            for (int x: nums) {
                c += combinationSum4(nums, target - x);
            }
            memo[target] = c;
        }
        return memo[target];
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> A(target + 1, 0);
        for (int x: nums) {
            if (x >= 0 && x <= target) {
                A[x] = 1;
            }
        }
        for (int k = 0; k < target + 1; k++) {
            for (int x: nums) {
                if ((k - x) >= 0) {
                    A[k] += A[k - x];
                }
            }
        }
        return A[target];
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> A(target + 1, 0);
        A[0] = 1;
        for (int k = 0; k < target + 1; k++) {
            for (int x: nums) {
                if ((k - x) >= 0) {
                    A[k] += A[k - x];
                }
            }
        }
        return A[target];
    }
};

