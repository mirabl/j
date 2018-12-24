class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int s = 0;
        for (int d = 0; d <= n; d++) {
            int x = 1;
            for (int i = 0; i < d; i++) {
                if (i < 2) {
                    x = x * 9;
                }  else {
                    x = x * (9 - i + 1);
                }
            }
            s += x;
        }
        return s;
    }
};