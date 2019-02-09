class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> S;
        for (auto x: A) {
            if (S.count(x) == 1) {
                return x;
            }
            S.insert(x);
        }
        return -1; // NR
    }
};
