class Solution {
public:
    bool isSelfDividing(int x) {
        int y = x;
        while (y != 0) {
            int d = y % 10;
            if (d == 0 || x % d != 0) {
                return false;
            }
            y = y / 10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};