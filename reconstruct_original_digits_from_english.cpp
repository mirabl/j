class Solution {
public:
    string originalDigits(string s) {
        vector<int> count_digit(10, 0);
        count_digit[0] = count(s.begin(), s.end(), 'z');
        count_digit[2] = count(s.begin(), s.end(), 'w');
        count_digit[4] = count(s.begin(), s.end(), 'u');
        count_digit[6] = count(s.begin(), s.end(), 'x');
        count_digit[8] = count(s.begin(), s.end(), 'g');
        count_digit[3] = count(s.begin(), s.end(), 't') - count_digit[2] - count_digit[8];
        count_digit[5] = count(s.begin(), s.end(), 'f') - count_digit[4];
        count_digit[7] = count(s.begin(), s.end(), 's') - count_digit[6];
        count_digit[1] = count(s.begin(), s.end(), 'o') - count_digit[0] - count_digit[2] - count_digit[4];        
        count_digit[9] = (count(s.begin(), s.end(), 'n') - count_digit[1] - count_digit[7]) / 2;
        string res;
        for (int i = 0; i < 10; i++) {
            res.insert(res.end(), count_digit[i], char(i) + '0');
        }
        return res;
    }
};