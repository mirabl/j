class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int a = 0;
        int i = 0;
        while (n != 0) {
            if (m == n) {
                a = a | ((m & 1) << i);
            }
            m >>= 1;
            n >>= 1;
            i++;
        }
        return a;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m /= 2;
            n /= 2;
            i++;
        }
        return m << i;
    }
};

