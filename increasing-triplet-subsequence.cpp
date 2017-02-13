class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty()) { 
            return false;
        }
        int y = -1;
        int z = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int t = nums[i];
            if (y != -1 && t > y) {
                return true;
            }
            if (t > z) {
                y = t;
            }
            z = min(z, t);
        }
        return false;
    }
};