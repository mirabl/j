class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustedBy(N + 1), trustN(N + 1);
        for (auto t: trust) {
            auto a = t[0];
            auto b = t[1];
            trustedBy[b]++;
            trustN[a]++;
        }
        
        int cand = -1;
        for (int i = 1; i <= N; i++) {
            if (trustedBy[i] == N - 1 && trustN[i] == 0) {
                if (cand != -1) {
                    return -1;
                }
                cand = i;
            }
        }
        
        return cand;
    }
};
