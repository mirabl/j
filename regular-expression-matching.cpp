class Solution {
public:
    bool match(string& s, string& p, int i, int j) {
        if (i == s.size() && j == p.size()) {
                return true;
        }
        
        if (j < p.size() - 1) {
            if (p[j + 1] == '*') {
                if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
                    return match(s, p, i + 1, j) || match(s, p, i, j + 2);
                } else {
                    return match(s, p, i, j + 2);
                }
            }
        }
        return i < s.size() && (p[j] == '.' || s[i] == p[j]) && match(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }
};

// Also DP
// https://discuss.leetcode.com/category/18/regular-expression-matching