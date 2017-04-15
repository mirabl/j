class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }
        if (k == 0) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == nums[i - 1]) {
                    return true;
                }
            }
            return false;
        } else {
            k = k > 0 ? k : -k;
            unordered_set<int> S;
            int sum = nums[0] % k;
            S.insert(0);
            S.insert(sum);
            for (int i = 1; i < nums.size(); i++) {
                sum = (sum + nums[i]) % k;
                 if (S.count(sum) == 1) {
                    return true;
                } 
                S.insert(sum);
            }
            return false;
        }
    }
};

// could be simplified
//https://discuss.leetcode.com/topic/80793/java-o-n-time-o-k-space