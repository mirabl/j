class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int x = 1;
        while (int(res.size()) != n) {
            res.push_back(x);
            if (x * 10 <= n) {
                x = x * 10;
            } else {
                while ((x % 10) == 9 || x + 1 > n) {
                    x = x / 10;
                }
                x = x + 1;
            }
        }
        return res;
    }
};