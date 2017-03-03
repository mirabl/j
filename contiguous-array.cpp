class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> H;
        int N = nums.size();
        int s = 0;
        int m = 0;
        H[0] = -1;
        for (int i = 0; i < N; i++) {
            s += (nums[i] == 1 ? 1 : -1);
            if (H.count(s) == 1) {
                m = max(m, i - H[s]);
            } else {
                H[s] = i;
            }
        }
        return m;
    }
};