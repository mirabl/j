class Solution {
public:
    double bestSumOfAvgs(vector<int>& A, int K, int i, map<pair<int, int>, double>& memo) {
        if (K == 0) {
            if (i == -1) {
                return 0.0;
            } else {
                return -1e6;
            }
        }
        
        if (memo.count({K, i}) == 0) {
            double m = -1;
            for (int j = i; j >= 0; j--) {
                // new chunk from j to i inclusive
                double avg = 0;
                for (int k = j; k <= i; k++) {
                    avg += A[k];
                }
                avg /= i - j + 1;
                m = max(m, avg + bestSumOfAvgs(A, K - 1, j - 1, memo));
            }
            memo[{K, i}] = m;
        }
        return memo[{K, i}];
    }
    
    double largestSumOfAverages(vector<int>& A, int K) {
        map<pair<int, int>, double> memo;
        return bestSumOfAvgs(A, K, A.size() - 1, memo);
    }
};
