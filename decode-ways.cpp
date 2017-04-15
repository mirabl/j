class Solution {
public:
    int numDecodings(string s) {
        int x = s.empty() || s.back() == '0' ? 0 : 1;
        int y = 1;
        for (int i = s.size() - 2; i >= 0; i--) {
            int tmp = x;
            if (s[i] != '0') {
                if (stoi(s.substr(i, 2)) <= 26) {
                    x += y;
                }
            } else {
                x = 0;
            }
            y = tmp;
        }
        return x;
    }
};