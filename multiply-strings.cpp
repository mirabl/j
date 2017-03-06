class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int c = 0;
        for (int i = 0; i < num1.size() + num2.size() - 1; i++) {
            int z = c;
            for (int j = 0; j <= i; j++) {
                int x = j < num1.size() ? num1[j] - '0' : 0;
                int y = i - j < num2.size() ? num2[i - j] - '0' : 0;
                z += x * y;
            }
            res.push_back((z % 10) + '0');
            c = z / 10;
        }
        if (c != 0) {
            res.push_back((c % 10) + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};