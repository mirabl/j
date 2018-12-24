/*
https://leetcode.com/problems/longest-common-prefix/
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = int(strs.size());
        if (n == 0) {
            return string("");
        }
        if (n == 1) {
            return strs[0];
        }
        
        for (int l = strs[0].size(); l >= 0; --l) {
            string p = strs[0].substr(0, l);
            int i = 1;
            for (; i < n; ++i) {
                if (p != strs[i].substr(0, l)) {
                    break;
                }
            }
            if (i == n) {
                return p;
            }
        }
        return string("");
    }
};