class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int z = 0;
        for (int n: nums) {
            z ^= n;
        }
        int i = 0;
        while (((z >> i) & 1) == 0) {
            i++;
        }
        int a = 0;
        int b = 0;
        for (int n: nums) {
            if (((n >> i) & 1) == 1) {
                a = a ^ n;
            } else {
                b = b ^ n;
            }
        }
        return {a, b};
    }
};