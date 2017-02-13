class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        const int n = nums.size();
        for (int x: findNums) {
            int i = 0;
            while (nums[i] != x) {
                i++;
            }
            while (i < n && nums[i] <= x) {
                i++;
            }
            if (i != n) {
                res.push_back(nums[i]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        const int n = nums.size();
        nums.push_back(-1);
        for (int x: findNums) {
            int i = 0;
            while (nums[i] != x) {
                i++;
            }
            while (i < n && nums[i] <= x) {
                i++;
            }
            res.push_back(nums[i]);
        }
        return res;
    }
};

