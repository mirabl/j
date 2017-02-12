class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> A;
        const int n = int(nums.size());
        for (int i = 0; i < n; i++) {
            A.push_back({nums[i], i});
        }
        sort(A.begin(), A.end());
        vector<string> res(n);
        int i = 0;
        while (i < n - 3) {
            res[A[i].second] = to_string(n - i);
            i++;
        }
        vector<string> medals{"Gold Medal", "Silver Medal", "Bronze Medal"};
        while (i < n) {
            res[A[i].second] = medals[n - 1 - i];
            i++;
        }
        return res;
    }
};