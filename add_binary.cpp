class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        const int n = int(a.size());
        const int m = int(b.size());
        int c = 0;
        for (int i = 0; i < max(n, m); i++) {
            if (i < n) {
                c += int(a[n - 1 - i] - '0');
            }
            if (i < m) {
                c += int(b[m - 1 - i] - '0');
            }
            res.push_back(char('0' + (c % 2)));
            c = c / 2;
        }
        if (c != 0) {
            res.push_back(char('0' + (c % 2)));
        }

        reverse(res.begin(), res.end());
        return res;
    }
};