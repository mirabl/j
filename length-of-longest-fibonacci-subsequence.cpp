class Solution {
public:
    int findLen(set<int>& S, int x, int y, int l) {
        int z = x + y;
        if (S.count(z) == 1) {
            return findLen(S, y, z, l + 1);
        } else {
            return l;
        }
    }
    
    int lenLongestFibSubseq(vector<int>& A) {
        set<int> S;
        for (auto x: A) {
            S.insert(x);
        }
        int best = 0;
        for (int i = 0; i < int(A.size()); i++) {
            for (int j = i + 1; j < int(A.size()); j++) {
                int l = findLen(S, A[i], A[j], 2);
                best = l > 2 ? max(l, best) : best;
            }
        }
        return best;
    }
};