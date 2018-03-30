class Solution {
public:
    map<int, set<int>> G;
    map<int, set<int>> iG;
    int n;
    set<int> remainingVertices;
    
    bool isTerminal(int i) {
        return G[i].empty();
    }
    
    void removeVertex(int i) {
        for (int j: iG[i]) {
            G[j].erase(i);
        }
    }

    void makeGraph(vector<vector<int>>& graph) {
        n = graph.size();
        for (int i = 0; i < n; i++) {
            for (auto j: graph[i]) {
                G[i].insert(j);
                iG[j].insert(i);
            }
        }
        for (int i = 0; i < n; i++) {
            remainingVertices.insert(i);
        }
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        makeGraph(graph);
        set<int> S;

        for (int round = 0; round <= n; round++) {
            set<int> toRemove;
            for (int i: remainingVertices) {
                if (isTerminal(i)) {
                    removeVertex(i);
                    toRemove.insert(i);
                }
            }
            if (toRemove.empty()) {
                break;
            }
            for (int i: toRemove) {
                remainingVertices.erase(i);
                S.insert(i);
            }
        }
        vector<int> res(S.begin(), S.end());
        sort(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    map<int, int> degree;
    map<int, set<int>> iG;
    int n;
    set<int> remainingVertices;
    
    bool isTerminal(int i) {
        return degree[i] == 0;
    }
    
    void removeVertex(int i) {
        for (int j: iG[i]) {
            degree[j]--;
        }
    }

    void makeGraph(vector<vector<int>>& graph) {
        n = graph.size();
        for (int i = 0; i < n; i++) {
            for (auto j: graph[i]) {
                degree[i]++;
                iG[j].insert(i);
            }
        }
        for (int i = 0; i < n; i++) {
            remainingVertices.insert(i);
        }
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        makeGraph(graph);
        set<int> S;

        for (int round = 0; round <= n; round++) {
            set<int> toRemove;
            for (int i: remainingVertices) {
                if (isTerminal(i)) {
                    removeVertex(i);
                    toRemove.insert(i);
                }
            }
            if (toRemove.empty()) {
                 break;
            }
            for (int i: toRemove) {
                remainingVertices.erase(i);
                S.insert(i);
            }
        }
        vector<int> res(S.begin(), S.end());
        sort(res.begin(), res.end());
        return res;
    }
};