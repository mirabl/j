class Solution {
public:
    vector<int> partial(vector<int>& A, int L) {
        int n = A.size();
        vector<int> lS;
        int i;
        int c = 0;
        for (i = 0; i < L; i++) {
            c += A[i];
        }
        while (i < n) {
            lS.push_back(c);
            c -= A[i - L];
            c += A[i];
            i++;
        }
        lS.push_back(c);
        return lS;
    }
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> lS = partial(A, L);
        vector<int> mS = partial(A, M);
        
        int best = 0;
        int n = A.size();
        
        for (int i = 0; i <= n - L; i++) {
            for (int j = 0; j + M <= i; j++) {
                best = max(best, lS[i] + mS[j]);
            }
            
            for (int j = i + L; j <= n - M; j++) {
                best = max(best, lS[i] + mS[j]);
            }
        }
        
        return best;
    }
};
