class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int>::iterator it = max_element(nums.begin(), nums.end());
        int max_i = it - nums.begin();
        int max_val = *it;
        *it = -1;
        return max_val >= 2 * (*max_element(nums.begin(), nums.end())) ? max_i : -1;
    }
};

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int im1 = -1;
        int im2 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (im1 == -1 || nums[i] >= nums[im1]) {
                im2 = im1;
                im1 = i;
            } else if (im2 == -1 || nums[i] > nums[im2]) {
                im2 = i;
            }
        }
        if (im2 == -1 || nums[im1] >= 2 * nums[im2]) {
            return im1;
        } else {
            return -1;
        }
    }
};