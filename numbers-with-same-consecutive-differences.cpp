class Solution {
public:
    vector<int> s(vector<int>& res, int K) {
        vector<int> o;
        for (auto x: res) {
            int y = x % 10;
            vector<int> zz{y - K};
            if (K != 0) {
                zz.push_back(y + K);
            }
            for (auto z: zz) {
                if (z >= 0 && z <= 9) {
                    o.push_back(x * 10 + z);
                }
            }
        }
        return o;
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        for (int i = 1; i < N; i++) {
            res = s(res, K);
        }
        
        if (N == 1) {
            res.push_back(0);
        }
        
        return res;
    }
};
