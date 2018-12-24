class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char c: s) {
            res = 26 * res + int(c - 'A' + 1);
        }
        return res;
    }
};