class Solution {
public:
    string convertToBase7(int num) {
        string s;
        if (num == 0) {
            s = "0";
        } else if (num < 0) {
            return "-" + convertToBase7(- num);
        }
        while (num != 0) {
            s = s + to_string(num % 7);
            num /= 7;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};