class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> n1before(n), n0after(n);
        
        for (int i = 0; i < n; i++) {
            n1before[i] = (i > 0 ? n1before[i - 1] : 0) + (S[i] == '1' ? 1 : 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            n0after[i] = (i < n - 1 ? n0after[i + 1] : 0) + (S[i] == '0' ? 1 : 0);
        }
        
        int v = n + 1;
        for (int i = 0; i < n; i++) {
            v = min(v, n1before[i] + (i < n - 1 ? n0after[i + 1] : 0));
        }
        
        v = min(v, n0after[0]);

        return v;
    }
};
