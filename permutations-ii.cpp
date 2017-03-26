class Solution {
public:
    void rec(vector<int>& nums, int offset, vector<vector<int>>& res) {
        if (offset == nums.size()) {
            res.push_back(nums);
        } else {
            set<int> done;
            for (int i = offset; i < nums.size(); i++) {
                if (done.count(nums[i]) == 1) {
                    continue;
                }
                swap(nums[i], nums[offset]);
                rec(nums, offset + 1, res);
                swap(nums[i], nums[offset]);
                done.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        rec(nums, 0, res);
        return res;
    }
};

class Solution {
public:
    void rec(vector<int>& nums, int offset, vector<vector<int>>& res) {
        if (offset == nums.size()) {
            res.push_back(nums);
        } else {
            for (int i = offset; i < nums.size(); i++) {
                if (i > offset && nums[i - 1] == nums[i]) {
                    continue;
                }
                int tmp = nums[i];
                for (int j = i; j > offset; j--) {
                    nums[j] = nums[j - 1];
                }
                nums[offset] = tmp;
                rec(nums, offset + 1, res);
                tmp = nums[offset];
                for (int j = offset; j < i; j++) {
                    nums[j] = nums[j + 1];
                }
                nums[i] = tmp;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        rec(nums, 0, res);
        return res;
    }
};

class Solution {
public:
    void rec(vector<int>& nums, int offset, vector<vector<int>>& res) {
        if (offset == nums.size()) {
            res.push_back(nums);
        } else {
            for (int i = offset; i < nums.size(); i++) {
                if (i > offset && nums[offset] == nums[i]) {
                    continue;
                }
                swap(nums[offset], nums[i]);
                rec(nums, offset + 1, res);
            }
            for (int j = offset; j < nums.size() - 1; j++) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        rec(nums, 0, res);
        return res;
    }
};