class Solution {
public:
    bool c(vector<int>& v) {
        if (v.size() % 2 != 0) {
            return false;
        }
        map<char, int> f;
        for (auto x: v) {
            f[x]++;
        }
        sort(v.begin(), v.end());
        for (auto x: v) {
            if (f[x] == 0) {
                continue;
            }
            int y = 2 * x;
            if (f[y] == 0) {
                return false;
            }
            f[y]--;
            f[x]--;
        }
        return true;
    }
    
    bool canReorderDoubled(vector<int>& A) {
        vector<int> pos, neg, zero;
        for (auto x: A) {
            if (x > 0) {
                pos.push_back(x);
            } else if (x < 0) {
                neg.push_back(- x);
            } else {
                zero.push_back(x);
            }
        }
        return c(pos) && c(neg) && zero.size() % 2 == 0;   
    }
};
