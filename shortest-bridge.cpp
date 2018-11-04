class Solution {
public:
    int N, M;
    set<pair<int, int>> visited;
    vector<vector<int>> G;
    set<pair<int, int>> island1;
    vector<int> dr{1, -1, 0, 0};
    vector<int> dc{0, 0, -1, 1};
    
    void g(int row, int col) {
        if (G[row][col] != 1) {
            return;
        }
        G[row][col] = 2;
        island1.insert({row, col});

        for (int i = 0; i < 4; i++) {
            int r2 = row + dr[i];
            int c2 = col + dc[i];
            if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < M) { 
                if (G[r2][c2] == 1)
                    g(r2, c2);
            }
        }   
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        N = A.size();
        M = A[0].size();
        G = vector<vector<int>>(A);
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M && island1.empty(); c++) {
                if (A[r][c] == 1) {
                    g(r, c);
                }
            }
        }
        
 
        queue<pair<int, int>> Q;
        for (auto x: island1) {
            Q.push(x);
            visited.insert(x);
        }
        int res = 0;
        while (!Q.empty()) {
            int n = Q.size();
            while (n > 0) {
                auto p = Q.front();
                Q.pop();
                int row = p.first;
                int col = p.second;
                if (G[row][col] == 1) {
                    return res - 1;
                }                    
                
                for (int i = 0; i < 4; i++) {
                    int r2 = row + dr[i];
                    int c2 = col + dc[i];
                    if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < M && visited.count({r2, c2}) == 0) { 
                        Q.push({r2, c2});
                        visited.insert({r2, c2});
                    }
                }   
                
                n--;
            }
            res++;
        }
        
        return -2;
    }
};
