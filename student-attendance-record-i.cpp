class Solution {
public:
    bool checkRecord(string s) {
        int cnt_A = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                cnt_A++;
                if (cnt_A == 2) {
                    return false;
                }
            } else if (i >= 2 && s[i] == 'L' && s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkRecord(string s) {
        bool absent = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                if (absent) {
                    return false;
                }
                absent = true;
            } else if (i >= 2 && s[i] == 'L' && s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
                return false;
            }
        }
        return true;
    }
};

/// -------------

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int l = 0;
        for (char c: s) {
            if (c == 'A') {
                a++;
            }
            if (c == 'L') {
                l++;
            } else {
                l = 0;
            }
            if (a >= 2 || l > 2) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int l = 0;
        for (char c: s) {
            if (c == 'A') {
                a++;
            }
            l = c == 'L' ? l + 1 : 0;
            if (a >= 2 || l > 2) {
                return false;
            }
        }
        return true;
    }
};

