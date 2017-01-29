class Solution {
public:
    string addStrings(string num1, string num2) {
        const int n = int(num1.size());
        const int m = int(num2.size());
        const int l = max(n, m);
        int carry = 0;
        string res = "";
        for (int i = 0; i < l; i++) {
            int c1 = (i < n ? int(num1[n - 1 - i] - '0') : 0);
            int c2 = (i < m ? int(num2[m - 1 - i] - '0') : 0);
            res = res + char(((c1 + c2 + carry) % 10) + '0');
            carry = (c1 + c2 + carry) / 10;
        }
        if (carry != 0) {
            res = res + char(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};