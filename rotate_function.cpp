/*
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int f = 0;
        int N = int(A.size());
        int S = 0;
        for (int i = 0; i < N; i++) {
            f += i * A[i];
            S += A[i];
        }
        int maxf = f;
        for (int k = 1; k < N; k++) {
            f = f + S - (N ) * A[N - k];
            maxf = max(maxf, f);
        }
        return maxf;
    }
};