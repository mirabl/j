class Solution {
public:
    map<int, vector<int>> G;
    vector<set<int>> groups;
    
    bool dfs(int i, int group) {
        if (groups[1 - group].count(i) == 1) {
            return false;
        } 
        
        if (groups[group].count(i) == 1) {
            return true;
        }
        
        groups[group].insert(i);
        for (auto j: G[i]) {
            if (!dfs(j, 1 - group)) {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for (auto v: dislikes) {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        groups.resize(2);
        
        for (int i = 0; i < N; i++) {
            if (groups[0].count(i + 1) == 0 && groups[1].count(i + 1) == 0 && !dfs(i + 1, 0)) {
                return false;
            }
        }
        return true;
    }
};
