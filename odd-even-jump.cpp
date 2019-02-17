class Solution {
public:
    int NOT_EXISTS = -1;
    map<pair<int, bool>, bool> ok;
    
    void gg(vector<int>& A, int n, vector<int>& nextBigger) {
        set<int> S;
        map<int, int> idx;
        for (int i = n - 1; i >= 0; i--) {
            auto lo = S.lower_bound(A[i]);
            if (lo == S.end()) {
                nextBigger[i] = NOT_EXISTS;
            } else {
                nextBigger[i] = idx[*lo];
            }
            S.insert(A[i]);
            idx[A[i]] = i;
        }
    }
    
    bool jj(int i, vector<int>& nB, vector<int>& nS, bool odd) {
        if (i == -1) {
            return false;
        }
        
        if (ok.count({i, odd}) != 1) {
            int j = odd ? nB[i] : nS[i];
            ok[{i, odd}] = jj(j, nB, nS, !odd);
        }
        
        return ok[{i, odd}];
    }
    
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<int> nextBigger(n);
        vector<int> nextSmaller(n);

        gg(A, n, nextBigger);
        
        vector<int> B;
        for (auto x: A) {
            B.push_back(-x);
        }
        
        gg(B, n, nextSmaller);
       
        int res = 0;
        
        ok[{n - 1, true}] = true; // odd
        ok[{n - 1, false}] = true;

        for (int i = 0; i < n; i++) {
            if (jj(i, nextBigger, nextSmaller, true)) {
                res++;
            }
        }  
        return res;
    }
};
