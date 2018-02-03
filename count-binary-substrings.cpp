class Solution {
public:
    int numberOfStartingAt(string s, int start) {
        int res = start + 1;
        while (res < s.size() && s[res] == s[start]) {
            res++;
        }
        return res - start;
    }
    
    int countBinarySubstrings(string s) {
        int res = 0;
        int last = 0;
        int pos = 0;
        while (pos < s.size()) {
            int cur = numberOfStartingAt(s, pos);
            int len = min(cur, last);
            res += len;
            last = cur;
            pos += cur;
        }
        return res;
    }
};