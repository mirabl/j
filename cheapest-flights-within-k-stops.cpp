class Solution {
public:
    const int INFTY = 1e6;
    vector<vector<int>> D, Dsteps;
    int N;
    
    void makeGraph(int n, vector<vector<int>>& flights) {
        N = n;
        D.resize(N);
        for (int i = 0; i < N; i++) {
            D[i].resize(N);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                D[i][j] = INFTY;
            }
        }
        
        for (auto flight: flights) {
            D[flight[0]][flight[1]] = flight[2];
        }
        Dsteps = D;
    }
    
    void updateOneRound() {
        auto D2 = Dsteps;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (Dsteps[i][k] + D[k][j] < INFTY) {
                        D2[i][j] = min(D2[i][j], Dsteps[i][k] + D[k][j]);
                    }
                }
            }
        }
        Dsteps = D2;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        makeGraph(n, flights);
        
        for (int k = 0; k < K; k++) {
            updateOneRound();
        }
        
        return Dsteps[src][dst] != INFTY ? Dsteps[src][dst] : -1;
    }
};