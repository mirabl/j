class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) {
            return vector<int>{0};
        }
        vector<int> res = grayCode(n - 1);
        int k = res.size();
        for (int i = 0; i < k; i++) {
            res.push_back(k + res[k - i - 1]);
        }
        return res;
    }
};