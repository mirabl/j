class Solution {
public:
    map<int, vector<int>> G;
    vector<int> memo;
    
    int minQ(int root, vector<int>& quiet) {
        if (memo[root] == - 1) {
            memo[root] = root;
            for (auto y: G[root]) {
                int x = minQ(y, quiet);
                if (quiet[x] < quiet[memo[root]]) {
                    memo[root] = x;
                }
            }
        }
        return memo[root];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> res;
        memo = vector<int>(n, -1);
        
        for (auto v: richer) {
            G[v[1]].push_back(v[0]);
        }
        for (int i = 0; i < n; i++) {
            res.push_back(minQ(i, quiet));
        }
        return res;
    }
};
