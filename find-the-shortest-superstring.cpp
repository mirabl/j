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

class Solution {
public:
    int N;
    
    int ov(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        for (int o = min(n, m); o > 0; o--) {
            string td = t.substr(0, o);
            string sd = s.substr(n - 1 - o + 1);
            if (td == sd) {
                return o;
            }
        }
        return 0;
    }
    
    string shortestSuperstring(vector<string>& A) {
        N = A.size();
        int infty = 1e9;
        
        vector<vector<int>> overlap(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                overlap[i][j] = ov(A[i], A[j]);
            }
        }
        
        int m = 1 << N;
        vector<vector<int>> dp(m, vector<int>(N, infty));
        vector<vector<int>> prev(m, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            dp[1 << i][i] = A[i].size();
            prev[1 << i][i] = -1;
        }
        for (int mask = 0; mask < m; mask++) {
            for (int i = 0; i < N; i++) {
                if ((mask >> i) & 1 == 1) {
                    continue;
                }
                for (int j = 0; j < N; j++) {
                    int u = dp[mask][j] + int(A[i].size()) - overlap[j][i];
                    int newMask = mask | (1 << i);
                    if (u < dp[newMask][i]) {
                        dp[newMask][i] = u;
                        prev[newMask][i] = j;
                    }

                }
            }
        }
        int mask = (1 << N) - 1;
        string res;
        int bestI = 0;
        for (int i = 0; i < N; i++) {
            if (dp[mask][i] < dp[mask][bestI]) {
                bestI = i;
            }
        }
        res = re(A, overlap, dp, prev, mask, bestI) + A[bestI];
        
        return res;
    }
    
    string re(vector<string>& A, vector<vector<int>>& overlap, vector<vector<int>>& dp, vector<vector<int>>& prev, int mask, int i) {
       int ni = prev[mask][i];
        if (ni == -1) {
            return "";
        }
        string s = A[ni].substr(0, A[ni].size() - 1 - overlap[ni][i] + 1);
        return re(A, overlap, dp, prev, mask ^ (1 << i), ni) + s;
    }
};


class Solution {
public:
    int infty = 1e8;
    
    int cov(string& s, string& t) {
        int n = min(s.size(), t.size());
        for (int l = n; l >= 1; l--) {
            string s2 = s.substr(s.size() - l);
            string t2 = t.substr(0, l);
            if (s2 == t2) {
                return l;
            }
        }
        
        return 0;
    }
    
    string shortestSuperstring(vector<string>& A) {
        int N = A.size();
        vector<vector<int>> ov(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                ov[i][j] = cov(A[i], A[j]);
            }
        }
        
        int M = 1 << N;
        vector<vector<int>> dp(M, vector<int>(N, infty));
        vector<vector<int>> prev(M, vector<int>(N, -1));
        for (int i = 0; i < N; i++) {
            dp[1 << i][i] = A[i].size();
        }
        
        for (int m = 0; m < M; m++) {
            for (int i = 0; i < N; i++) {
                if ((m >> i) & 1 == 0) {
                    continue;
                }
                for (int j = 0; j < N; j++) {
                    if ((m >> j) & 1 == 1) {
                        continue;
                    }
                    int m2 = m | (1 << j);
                    int v = dp[m][i] + A[j].size() - ov[i][j];
                    if (v < dp[m2][j]) {
                        dp[m2][j] = v;
                        prev[m2][j] = i;
                    }
                }
            }
        }
        
        vector<int> res;
        int j = 0;
        int m = M - 1;
        for (int i = 0; i < N; i++) {
            if (dp[m][i] < dp[m][j]) {
                j = i;
            }
        }
        while (j != -1) {
            res.insert(res.begin(), j);
            int m2 = m ^ (1 << j);
            j = prev[m][j];  
            m = m2;
        }
        
        string r = A[res[0]];
        for (int i = 1; i < N; i++) {
            r += A[res[i]].substr(ov[res[i - 1]][res[i]]);
        }
        
        
        return r;
    }
};
