class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        int last1 = -1;
        for (int i = 31; i >= 0; i--) {
            if ((N >> i) & 1 == 1) {
                if (last1 != -1) {
                    res = max(res, last1 - i);
                }
                last1 = i;
            }
        }
        return res;
    }
};
