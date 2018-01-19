class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (i != 0 && nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i + 1];
                }
                for (int j = i + 1; j < nums.size() - 1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        return false;
                    }
                }
                return true;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i] > nums[i + 1]) {
                if (i != 0 && nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i + 1];
                }
                break;
            }
            i++;
        }
        while (i < nums.size() - 1) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
            i++;
        }
        return true;
    }
};
