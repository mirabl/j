class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int INFTY = 1e9;
        vector<int> dL(n, 0), dR(n, 0);
        dL[0] = seats[0] == 0 ? INFTY : 0;
        for (int i = 1; i < n; i++) {
            if (seats[i] == 0) {
                dL[i] = dL[i - 1] + 1;
            }
        }
        dR[n - 1] = seats[n - 1] == 0 ? INFTY : 0;
        for (int i = n - 2; i >= 0; i--) {
            if (seats[i] == 0) {
                dR[i] = dR[i + 1] + 1;
            }
        }
        int best = 0;
        for (int i = 0; i < n; i++) {
            best = max(best, min(dL[i], dR[i]));
        }
        return best;
    }
};
