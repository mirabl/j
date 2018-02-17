class Solution {
public:
    bool isInTheBoard(int N, int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < N;
    }
    
    int key(int r, int c, int K, int N) {
        return r + N * c + N * N * K;
    }
    
    double knightProbability(int N, int K, int r, int c, unordered_map<int, double>& M) {
        if (!isInTheBoard(N, r, c)) {
            return 0.0;
        }
        if (K == 0) {
            return 1.0;
        }
        if (M.count(key(r, c, K, N)) == 0) {
            double p = 0.0;
            vector<int> dc{2, 1, -1, -2, -2, -1, 1, 2};
            vector<int> dr{1, 2, 2, 1, -1, -2, -2, -1};
            for (int i = 0; i < 8; i++) {
                p += 1/8. * knightProbability(N, K - 1, r + dr[i], c + dc[i], M);
            }
            M[key(r, c, K, N)] =  p;
        }
        return M[key(r, c, K, N)];
    }
    
    double knightProbability(int N, int K, int r, int c) {
        unordered_map<int, double> M;
        return knightProbability(N, K, r, c, M);
    }

};