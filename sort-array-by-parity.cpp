class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> a, b;
        for (auto x: A) {
            if (x % 2 == 0) {
                a.push_back(x);
            } else {
                b.push_back(x);
            }
        }
        for (auto x: b) {
            a.push_back(x);
        }
        return a;
    }
};
