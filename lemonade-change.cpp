class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n5 = 0;
        int n10 = 0;
        
        for (auto c: bills) {
            if (c == 5) {
                n5++;
                continue;
            } else if (c == 10) {
                if (n5 == 0) {
                    return false;
                }
                n5--;
                n10++;
            } else {
                if (n10 > 0 && n5 > 0) {
                    n10--;
                    n5--;
                } else if (n5 > 2) {
                    n5 -= 3;
                } else {
                    return false;
                }
            }
        }
        
        
        return true;
    }
};
