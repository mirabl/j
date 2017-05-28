class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);
        int best = 0;
        for (int i = 0; i < n && best <= n / 2; i++) { // TLE without <= n/2
            if (seen[i]) {
                continue;
            }
            int k = i;
            int len = 0;
            do {
                seen[i] = true;
                k = nums[k];
                len++;
            } while (k != i);
            best = max(best, len);
        }
        return best;
    }
};