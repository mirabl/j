class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> H;
        H[0] = {0};
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            H[s].push_back(i + 1);
        }
        s = 0;
        int res = 0;
        for (int j = 0; j < nums.size(); j++) {
            s += nums[j];
            for (int i: H[s - k]) {
                if (i <= j) {
                    res++;
                }
            }
        }
        return res;
    }
};

// https://discuss.leetcode.com/topic/87850/java-solution-presum-hashmap

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> H;
        H[0] = 1;
        int s = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            if (H[s - k] != 0) {
                res += H[s - k];
            }
            H[s]++;
        }
        return res;
    }
};