class Solution {
public:
    void findPairWithSum(vector<int>& nums, int T, int lo, vector<vector<int>>& res) {
        int hi = nums.size() - 1;
        while (lo != hi) {
            if (nums[lo] + nums[hi] == T) {
                res.push_back({- T, nums[lo], nums[hi]});
            }
            if (nums[lo] + nums[hi] <= T) {
                do {
                    lo++;
                } while (lo != hi && nums[lo] == nums[lo - 1]);
            } else {
                hi--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            findPairWithSum(nums, - nums[i], i + 1, res);
        }
        return res;
    }
};

// can be simplified
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            //cout << i << endl;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                //cout << "  j=" << j << " k=" << k << endl;
                int y = nums[j] + nums[k];
                int c = nums[i];
                if (y < -c) {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                } else if (y > -c) {
                    k--;
                    while (k > j && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};

