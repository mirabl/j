class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int, int> comb2;
        int res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < A.size(); i++) {
            int y = target - A[i];
            res += comb2[y];
            res = res % mod;
            for (int j = 0; j < i; j++) {
                comb2[A[j] + A[i]]++;
            }
        }
        return res;
    }
};
