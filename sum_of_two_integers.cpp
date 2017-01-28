class Solution {
public:
    int getSum(int a, int b) {
        int s = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;
            int z = x ^ y ^ carry;
            carry = (x & y) | (x & carry) | (y & carry);
            s = s | z << i;
        }
        return s;
    }
};