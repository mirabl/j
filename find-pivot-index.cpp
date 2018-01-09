class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        int left = 0;
        int right = accumulate(nums.begin() + 1, nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (left == right) {
                return i;
            }
            left += nums[i];
            right -= i < nums.size() - 1 ? nums[i + 1] : 0;
        }
        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (total - nums[i] == 2 * left) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};

