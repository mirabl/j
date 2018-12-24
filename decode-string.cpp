/*
https://leetcode.com/problems/decode-string/
*/
class Solution {
public:
    string decodeString(string s) {
        string t;
        int i = 0;
        while (i < int(s.size())) {
            if (isdigit(s[i])) {
                int r = 0;
                int j = i;
                while (isdigit(s[j])) {
                    r = r * 10 + int(s[j] - '0');
                    ++j;
                }
                // s[j] == '['
                i = j + 1;
                j = i;
                int num_open = 1;
                while (num_open != 0) {
                    if (s[j] == '[') {
                        num_open++;
                    } else if (s[j] == ']') {
                        num_open--;
                    }
                    ++j;
                }
                --j; // s[j] = ']'
                string inside = decodeString(s.substr(i, j - i));
                while (r > 0) {
                    t += inside;
                    --r;
                }
                i = j + 1;
            } else {
                t += s[i];
                ++i;
            }
        }
        return t;
    }
};