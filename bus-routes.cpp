class Solution {
public:
    int N;
    map<int, set<int>> G;
    map<int, set<int>> stopsByLine;
    const int INFTY = 600;

    void buildGraph(vector<vector<int>>& routes) {
        N = routes.size();
        for (int r = 0; r < N; r++) {
            stopsByLine[r] = set<int>(routes[r].begin(), routes[r].end());
        }
        for (int r = 0; r < N; r++) {
            for (int s = r + 1; s < N; s++) {
                set<int> intersect;
                set_intersection(stopsByLine[r].begin(), stopsByLine[r].end(),
                                 stopsByLine[s].begin(), stopsByLine[s].end(),
                                 std::inserter(intersect,intersect.begin()));
                if (intersect.size() > 0) {
                    G[r].insert(s);
                    G[s].insert(r);
                }
            }
        }
    }

    int minStepsFrom(int r, int T) {
        queue<int> Q;
        Q.push(r);
        int steps = 1;
        set<int> visited;
        while (!Q.empty()) {
            int size = Q.size();
            while (size > 0) {
                int s = Q.front();
                Q.pop();
                size--;
                if (visited.count(s) > 0) {
                    continue;
                }
                visited.insert(s);
                if (stopsByLine[s].count(T) > 0) {
                    return steps;
                }
                for (int t: G[s]) {
                    Q.push(t);
                }
            }
            steps++;
        }
        return INFTY;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        buildGraph(routes);
        
        if (S == T) {
            return 0;
        }
        
        int minSteps = INFTY;
        for (int r = 0; r < N; r++) {
            if (stopsByLine[r].count(S) > 0) {
                minSteps = min(minSteps, minStepsFrom(r, T));
            }
        }
        return minSteps != INFTY ? minSteps : -1;
    }
};			
