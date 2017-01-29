class Solution {
public:
    string toHex(int num) {
        long long x;
        if (num >= 0) {
            x = num;
        } else {
            x = 0xffffffff + (1 + num);
        }
        string res;
        do {
            int y = x % 16;
            if (y < 10) {
                res = res + char(y + '0');
            } else {
                res = res + char(y - 10 + 'a');
            }
            x = x / 16;
        } while(x != 0);
        reverse(res.begin(), res.end());
        return res;
    }
};