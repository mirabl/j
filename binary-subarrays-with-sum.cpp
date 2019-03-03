class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> C{0};
        for (auto x: A) {
            C.push_back(x + C.back());
        }
        int res = 0;
        map<int, int> H;
        for (auto x: C) {
            res += H[x - S];
            H[x]++;
        }
        return res;
    }
};
