// https://leetcode.com/problems/rotated-digits/description/
class Solution {
public:
    
    bool rotatesToDiff(int x) {
        bool different = false;
        while (x != 0) {
            int d = x % 10;
            if (d == 3 || d == 4 || d == 7) {
                return false;
            } else if (d == 2 || d == 5 || d == 6 || d == 9) {
                different = true;
            }
            x /= 10;
        }
        return different;
    }
    
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; i++) {
            if (rotatesToDiff(i)) {
                res++;
            }
        }
        return res;
    }
};
