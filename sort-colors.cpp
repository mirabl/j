/*
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[] = {0, 0, 0};
        for (int i = 0; i < int(nums.size()); ++i) {
            counts[nums[i]]++;
        }
        int i = 0;
        for (int j = 0; j < 3; ++j) {
            while (counts[j] > 0) {
                nums[i] = j;
                counts[j]--;
                ++i;
            }
        }
    }
};

// 1.5 pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = int(nums.size());
        int j = n - 1;
        int i = 0;
        while (i <= j) {
            if (nums[i] == 2) {
                swap(nums[i], nums[j]);
                --j;
            } else {
                ++i;
            }
        }
        i = 0;
        while (i < j) {
            if (nums[i] == 1) {
                swap(nums[i], nums[j]);
                --j;
            } else {
                ++i;
            }
        }
        
    }
};

class Solution {
public:
    void srec(vector<int>& nums, int lo, int hi) {
        int i = lo;
        while (i < hi) {
            if (nums[i] == 0 || nums[i] == 2) {
                break;
            }
            ++i;
        }
        if (i == hi) {
            return; // all 1, or empty
        }
        if (nums[i] == 0) {
            swap(nums[i], nums[lo]);
            srec(nums, lo + 1, hi);
        } else {
            swap(nums[i], nums[hi - 1]);
            srec(nums, lo, hi - 1);
        }
        
    }

    void sortColors(vector<int>& nums) {
        srec(nums, 0, int(nums.size()));
    }
};

    void sortColors(vector<int>& nums) {
        int lo = 0;
        int hi = int(nums.size());
        while (lo < hi) {
            int i = lo;
            while (i < hi) {
                if (nums[i] == 0 || nums[i] == 2) {
                    break;
                }
                ++i;
            }
            if (i == hi) {
                return; // all 1, or empty
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[lo]);
                lo = lo + 1;
            } else {
                swap(nums[i], nums[hi - 1]);
                hi = hi - 1;
            }
        }
    }

    