class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int left = A[0] + 0;
        int best = -1;
        for (int i = 1; i < A.size(); i++) {
            int right = A[i] - i;
            best = max(best, left + right);
            left = max(left, A[i] + i);
        }
        return best;
    }
};
