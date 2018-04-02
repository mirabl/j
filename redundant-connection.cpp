class Solution {
public:
    map<int, set<int>> G;
    int N;
    set<int> visited;
    
    vector<int> findLastEdge(vector<int>& path, vector<vector<int>>& edges) {
        path.push_back(path[0]);
        set<vector<int>> cycleEdges;
        for (int i = 0; i < path.size() - 1; i++) {
            cycleEdges.insert({path[i], path[i + 1]});
            cycleEdges.insert({path[i + 1], path[i]});
        }
        
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycleEdges.count(edges[i]) == 1) {
                return edges[i];
            }
        }
        
        return {}; // NR.
    }
    
    void makeGraph(vector<vector<int>>& edges) {
        N = edges.size();
        for (auto edge: edges) {
            G[edge[0]].insert(edge[1]);
            G[edge[1]].insert(edge[0]);
        }
    }
    
    bool dfsFindCycle(int i, vector<int>& currentPath) {
        visited.insert(i);
        for (int j: G[i]) {
            if (visited.count(j) == 1) {
                if (currentPath[currentPath.size() - 2] != j) {
                    while (currentPath[0] != j) {
                        currentPath.erase(currentPath.begin());
                    }
                    return true;
                }
            } else {
                currentPath.push_back(j);
                if (dfsFindCycle(j, currentPath)) {
                    return true;
                }
                currentPath.pop_back();
            }
        }
        return false;
    }
    
    vector<int> findCycle() {
        for (int i = 1; i <= N; i++) {
            vector<int> path{i};
            if (dfsFindCycle(i, path)) {
                return path;
            }
        }
        return {}; // Never reached.
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        makeGraph(edges);
        auto path = findCycle();
        return findLastEdge(path, edges);
    }
};