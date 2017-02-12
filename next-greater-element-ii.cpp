class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        priority_queue<pair<int, int>> PQ;
        const int n = int(nums.size());
        vector<int> res(n, -1);
        for (int j = 0; j < 2 * n; j++) {
            int i = j % n;
            while (!PQ.empty() && - nums[i] < PQ.top().first) {
                res[PQ.top().second] = nums[i];
                PQ.pop();
            }
            if (i < n) {
                PQ.push({- nums[i], i});
            }
        }
        return res;
    }
};