class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        map<int, map<int, int>> F;
        int N = A.size();
        for (int i = 0; i < N; i++) {
            if (F.count(A[i]) == 1) {
                for (auto candidate: F[A[i]]) {
                    int step = candidate.first;
                    int len = candidate.second;
                    F[A[i] + step][step] = max(F[A[i] + step][step], len + 1);
                    F[A[i]].erase(step);
                }
            }
            for (int j = 0; j < i; j++) {
                int step = A[i] - A[j];
                F[A[i] + step][step] = max(F[A[i] + step][step], 2);
            }
        }
        
        int infty = 1e8;
        int best = - infty;
        for (auto kvp: F) {
            for (auto cand: kvp.second) {
                best = max(best, cand.second);
            }
        }
        return best > - infty ? best : 0;
    }
};
