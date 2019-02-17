class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        map<int, int> H;
        int s = 0;
        H[s]++;
        for (auto x: A) {
            s = (((s + x) % K) + K) % K;
            H[s]++;
           // cout << "H " << s << " <- " << H[s] << endl;
        }
        
        int res = 0;
        for (int i = 0; i < K; i++) {
          //  cout << "H " << i << ": " << H[i] << endl;
            res += (H[i] * (H[i] - 1)) / 2;
        }
        return res;
    }
};
