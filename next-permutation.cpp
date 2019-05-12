class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i > 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        int j = n - 1;
        while (j > 0 && nums[j] <= nums[i]) {
            j--;
        }
        if (j == 0) {
            sort(nums.begin(), nums.end());
        } else {
            swap(nums[i], nums[j]);
            for (int k = 0; k <= (n - 1 - i - 1) / 2; k++) {
                swap(nums[i + 1 + k], nums[n - 1 - k]);
            }
        }

    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i > 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        int j = n - 1;
        while (j > 0 && nums[j] <= nums[i]) {
            j--;
        }
        if (j != 0) {
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + (j == 0 ? 0 : i + 1), nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            sort(nums.begin(), nums.end());
        }
        
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int k;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                k = j;
            }
        }
        
        swap(nums[i], nums[k]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
