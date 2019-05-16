class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int y = 0;
        for (int x: A) {
            y = y << 1 | x;
            y = y % 5;
            res.push_back(y % 5 == 0);
        }
        return res;
    }
};
