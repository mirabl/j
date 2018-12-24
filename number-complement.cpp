class Solution {
public:
    int findComplement(int num) {
        int i = 31;
        while (((num >> i) & 1) == 0) {
            i--;
        }
        i--;
        int res = 0;
        while (i >= 0) {
            if (((num >> i) & 1 ) == 0) {
                res = res | (1 << i);
            }
            i--;
        }
        return res;
    }
};