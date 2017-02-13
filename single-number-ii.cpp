class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < 32; i++) {
            int c = 0;
            for (int n: nums) {
                c += ((n >> (31-i)) & 1);
            }
            x = 2 * x;
            if (c % 3 != 0) {
                x++;
            
        }
        return x;
    }
};