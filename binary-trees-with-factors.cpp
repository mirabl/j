
// contest
class Solution {
public:
    long long mod = (1000000000 + 7);
    map<int, int> C;
    
    vector<pair<int, int>> getFactors(int x, set<int>& A) {
            vector<pair<int, int>> ans;
            for (int y: A) {
                if (x % y == 0 && A.count(x / y) == 1) {
                    ans.push_back({y, x / y});
                }
            }
            return ans;
    }
    
    long long nTreesWithRoot(int x, set<int>& B) {
        if (C.count(x) == 0) {
            long long ans = 1;
            auto factors = getFactors(x, B);
            for (auto p: factors) {
                ans += (nTreesWithRoot(p.first, B) * nTreesWithRoot(p.second, B)) % mod;
            }
            C[x] = ans % mod;
        }
        return C[x];
    }
    
    int numFactoredBinaryTrees(vector<int>& A) {
        set<int> B(A.begin(), A.end());
        
        long long ans = 0;
        for (int x: A) {
            ans += nTreesWithRoot(x, B);
            ans = ans % mod;
        }
        //cout << "nas " << ans << endl;
        return ans < 0 ? ans + mod : ans;
    }
};
