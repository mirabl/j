class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> count;
        for (int x: nums) {
            count[x]++;
        }
        int a = 0;
        int b = 0;
        for (int i = 0; i <= 10000; i++) {
            int c = max(count[i] * i + a, b);
            a = b;
            b = c;          
        }
        return b;
    }
};