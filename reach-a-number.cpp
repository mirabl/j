class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) {
            return reachNumber(- target);
        }
        for (int i = 0; ; i++) {
            int m = (i * (i + 1)) / 2;
            if (target >= -m && target <= m && target % 2 == m % 2) {
                return i;
            }
        }
    }
};