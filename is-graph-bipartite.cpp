class Solution {
public:
    map<int, set<int>> G;
    int N;
    typedef enum { UNKNOWN, BLACK, WHITE } color_t;
    map<color_t, color_t> other_color{{BLACK, WHITE}, {WHITE, BLACK}};
    vector<color_t> colors;
    
    void makeGraph(vector<vector<int>>& graph) {
        N = graph.size();
        for (int i = 0; i < N; i++) {
            for (int j: graph[i]) {
                G[i].insert(j);
                G[j].insert(i);
            }
        }
        colors.resize(N + 1, UNKNOWN);
    }
    
    bool dfs(int i, color_t color) {
        if (colors[i] == color) {
            return true;
        } else if (colors[i] == other_color[color]) {
            return false;
        }
        
        if (colors[i] == UNKNOWN) {
            colors[i] = color;
            for (int j: G[i]) {
                if (!dfs(j, other_color[color])) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        makeGraph(graph);
        for (int i = 0; i < N; i++) {
            if (colors[i] == UNKNOWN) {
                if (!dfs(i, BLACK)) {
                    return false;
                }
            }
        }
        return true;
    }
};