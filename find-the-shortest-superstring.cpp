class Solution {
public:
    vector<string> A;
    int N;
    vector<vector<int>> ov;
    
    int ovl(string s, string t) {
        int m = min(s.size(), t.size());
        while (m > 0) {
            string ss = s.substr(s.size() - m, m);
            string tt = t.substr(0, m);
            if (ss == tt) {
                break;
            }
            m--;
        }
        return m;
    }
    
    void co() {
        ov = vector<vector<int>>(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                
                ov[i][j] = ovl(A[i], A[j]);
            }
        }
    }
    int noPath = -2;

    string shortestSuperstring(vector<string>& A_) {
        A = A_;
        N = A.size();
        co();
        vector<vector<int>> dp(1 << N, vector<int>(N, noPath));
        vector<vector<int>> prev(1 << N, vector<int>(N, -1));
        
        for (int i = 0; i < N; i++) {
            dp[0][i] = 0;
        }
        
        for (int p = 0; p < (1 << N); p++) {
            for (int i = 0; i < N; i++) {
                if ((p >> i) & 1 == 1) {
                    continue;
                }
                int newp = p | (1 << i);
                for (int k = 0; k < N; k++) {
                    if ((p >> k) & 1 == 0 || dp[p][k] == noPath) {
                        continue;
                    }
                    int v = dp[p][k] + (p > 0 ? ov[k][i] : 0);
                    if (v > dp[newp][i]) {
                        dp[newp][i] = v;
                        prev[newp][i] = k;
                    }
                }
            }
        }
               
        int p = (1 << N) - 1;
        int k = 0;
        for (int i = 0; i < N; i++) {
            if (dp[p][i] > dp[p][k]) {
                k = i;
            }
        }
        string res;
        while (true) {
            int nextP = p ^ (1 << k);
            if (nextP == 0) {
                res = A[k] + res;
                break;
            } 
            int nextK = prev[p][k];
            res = A[k].substr(ov[nextK][k]) + res;
            k = nextK;
            p = nextP;
        }        
        return res;
    }
};
