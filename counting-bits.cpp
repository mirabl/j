class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 0; i < 31; i++) {
            for (int x = 1 << i; x <= num && x < (1 << (i + 1)); x++) {
                res[x] = i + 1 - res[(1 << (i + 1)) - 1 - x];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; i++) {
            res[i] = res[i / 2] + (i % 2);
        }

        return res;
    }
};