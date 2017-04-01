class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        int x = 1;
        int d = 2;
        for (; d*d < num; d++) {
            if (num % d == 0) {
                x += d + num / d;
            }
        }
        if (d * d == num) {
            num += d;
        }
        return num == x;
    }
};

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int x = 1;
        int d = 2;
        for (; d*d < num; d++) {
            if (num % d == 0) {
                x += d + num / d;
            }
        }
        if (d * d == num) {
            num += d;
        }
        return num > 1 && num == x;
    }
};