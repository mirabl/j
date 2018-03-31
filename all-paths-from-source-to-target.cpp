class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> G;
    int target;
    int N;
    
    void dfs(int source, vector<int>& path) {
        if (source == target) {
            res.push_back(path);
            return;
        }
        for (int v: G[source]) {
            path.push_back(v);
            dfs(v, path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        G = graph;
        N = G.size();
        target = N - 1;
        vector<int> path{0};
        dfs(0, path);
        return res;
    }
};