class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int j = 1;
        for (int i = 1; i < int(nums.size()); i++) {
            if (nums[j - 1] != nums[i]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};