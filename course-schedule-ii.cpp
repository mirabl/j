class Solution {
public:
    void dfs(vector<vector<int>>& M, int i, stack<int>& order, set<int>& visited) {
        if (visited.count(i) == 0) {
            visited.insert(i);
            for (int j = 0; j < M.size(); j++) {
                if (M[i][j] == 1) {
                    dfs(M, j, order, visited);
                }
            }
            order.push(i);
        }        
    }

    enum { NOT_VISITED, VISITING, VISITED };

    bool dfs_cycle(vector<vector<int>>& M, int i, vector<int>& state) {
        if (state[i] == NOT_VISITED) {
            state[i] = VISITING;
            for (int j = 0; j < M.size(); j++) {
                if (M[i][j] == 1) {
                    if (dfs_cycle(M, j, state)) {
                        return true;
                    }
                }
            }
            state[i] = VISITED;
        } else if (state[i] == VISITING) {
            return true; // Cycle!
        }
        return false;
    }

    bool hasCycle(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> state(M.size(), NOT_VISITED);
        for (int i = 0; i < n; i++) {
            if (dfs_cycle(M, i, state)) {
                return true;
            }
        }
        return false;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> M(numCourses, vector<int>(numCourses, 0));
        for (pair<int, int> edge: prerequisites) {
            M[edge.second][edge.first] = 1;
        }
        
        if (hasCycle(M)) {
            return {};
        }
        
        stack<int> order;
        set<int> visited;
        for (int i = 0; i < numCourses; i++) {
            dfs(M, i, order, visited);
        }
        vector<int> res;
        while (!order.empty()) {
            res.push_back(order.top());
            order.pop();
        }
        return res;
    }
};

//

class Solution {
public:
    enum { NOT_VISITED, VISITING, VISITED };

    bool dfs_cycle(vector<vector<int>>& M, int i, vector<int>& state, stack<int>& order) {
        if (state[i] == NOT_VISITED) {
            state[i] = VISITING;
            for (int j = 0; j < M.size(); j++) {
                if (M[i][j] == 1) {
                    if (dfs_cycle(M, j, state, order)) {
                        return true;
                    }
                }
            }
            state[i] = VISITED;
            order.push(i);
        } else if (state[i] == VISITING) {
            return true; // Cycle!
        }
        return false;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> M(numCourses, vector<int>(numCourses, 0));
        for (pair<int, int> edge: prerequisites) {
            M[edge.second][edge.first] = 1;
        }
        
        vector<int> state(numCourses, NOT_VISITED);
        stack<int> order;
        for (int i = 0; i < numCourses; i++) {
            if (dfs_cycle(M, i, state, order)) {
                return {};
            }
        }
        vector<int> res;
        while (!order.empty()) {
            res.push_back(order.top());
            order.pop();
        }
        return res;
    }
};

//

class Solution {
public:
    vector<vector<int>> G;
    int N;
    vector<int> sol;
    vector<int> state;
    
    bool dfs(int root) {
        if (state[root] == 1) {
            return false;
        }
        if (state[root] == 2) {
            return true;
        }
        state[root] = 1;
        for (int n: G[root]) {
            if (!dfs(n)) {
                return false;
            }
        }
        state[root] = 2;
        sol.insert(sol.begin(), root);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        N = numCourses;
        G = vector<vector<int>>(N);
        for (auto e: prerequisites) {
            G[e.second].push_back(e.first);
        }
        state = vector<int>(N, 0);
        for (int i = 0; i < N; i++) {
            if (!dfs(i)) {
                return {};
            }
        }
        return sol;
    }
};

//

class Solution {
public:
    vector<set<int>> G;
    int N;
    vector<int> sol;
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        N = numCourses;
        G = vector<set<int>>(N);
        vector<int> inDeg(N, 0);

        for (auto e: prerequisites) {
            G[e.second].insert(e.first);
            inDeg[e.first]++;
        }
        
        while (sol.size() != N) { 
            int mv = 0;
            for (int v = 0; v < N; v++) {
                if (inDeg[v] < inDeg[mv]) {
                    mv = v;
                }
            }

            if (inDeg[mv] > 0) { 
                return {};
            }

            sol.push_back(mv);

            for (auto n: G[mv]) {
                inDeg[n]--;
            }
            inDeg[mv] = 1e8;
        }
            
        return sol;
    }
};


class Solution {
public:
    vector<int> o;
    vector<int> state;
    int NOT_VISITED = 0;
    int VISITING = 1;
    int DONE = 2;
    map<int, vector<int>> G;
    
    bool dfs(int r) {
        if (state[r] == DONE) {
            return true;
        } else if (state[r] == VISITING) {
            return false;
        }
        state[r] = VISITING;
        
        for (auto s: G[r]) {
            if (!dfs(s)) {
                return false;
            }
        }
        o.push_back(r);
        state[r] = DONE;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        for (auto p: prerequisites) {
            G[p.second].push_back(p.first);
        }
        state = vector<int>(numCourses, NOT_VISITED);
        for (int s = 0; s < numCourses; s++) {
            if (!dfs(s)) {
                return {};
            }
        }
        
        vector<int> res;
        for (int i = numCourses - 1; i >= 0; i--) {
            res.push_back(o[i]);
        }
        return res;
    }
};
