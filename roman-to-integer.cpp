class Solution {
public:
    int romanToInt(string s) {
        map<string, int> M;
        M["I"] = 1;
        M["V"] = 5;
        M["X"] = 10;
        M["L"] = 50;
        M["C"] = 100;
        M["D"] = 500;
        M["M"] = 1000;
        M["IV"] = 4;
        M["IX"] = 9;        
        M["XL"] = 40;
        M["XC"] = 90;        
        M["CD"] = 400;
        M["CM"] = 900;
        
        int res = 0;
        int i = 0;
        while (i < int(s.size())) {
            string t = s.substr(i, 2);
            if (M.count(t) == 1) {
                i++;
            } else {
                t = s.substr(i, 1);
            }
            res += M[t];
            i++;
        }
        return res;
    }
};