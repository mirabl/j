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
	    // not necessary, can keep track of degree 0 vertices
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


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int N = numCourses;
        set<int> done;
        vector<int> deg(N);
        vector<vector<int>> G(N);
        for (auto p: prerequisites) {
            G[p.second].push_back(p.first);
            deg[p.first]++;
        }
        
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (res.size() != N) {
            if (q.empty()) {
                return {};
            }
            int u = q.front();
            q.pop();
            res.push_back(u);
            
            for (int v: G[u]) {
                deg[v]--;
                if (deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return res;
    }
};

class Solution {
public:
    enum {
        NOT_VISITED,
        VISITING,
        VISITED
    };
    
    bool dfs(vector<vector<int>>& G, int i, vector<int>& state, vector<int>& order) {
        if (state[i] == VISITED) {
            return true;
        } else if (state[i] == VISITING) {
            return false;
        }
        
        state[i] = VISITING;
        for (int j: G[i]) {
            if (!dfs(G, j, state, order)) {
                return false;
            }
        }
        
        order.push_back(i);
        state[i] = VISITED;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        for (auto p: prerequisites) {
            G[p[1]].push_back(p[0]);
        }
        
        vector<int> order;
        vector<int> state(numCourses, NOT_VISITED);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(G, i, state, order)) {
                return {};
            }
        }
        
        reverse(order.begin(), order.end());
        return order;
    }
};

class Solution {
public:
    typedef enum { NotVisited, Visiting, Visited } state;
    
    bool dfs(int i, vector<vector<int>>& G, vector<state>& states, vector<int>& order) {
        if (states[i] == Visiting) {
            return false;
        } else if (states[i] == Visited) {
            return true;
        }
        states[i] = Visiting;
        
        for (int j: G[i]) {
            if (!dfs(j, G, states, order)) {
                return false;
            }
        }
        
        states[i] = Visited;
        order.push_back(i);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<state> states(numCourses, NotVisited);
        vector<vector<int>> G(numCourses);
        for (auto p: prerequisites) {
            G[p[1]].push_back(p[0]);
        }
        
        vector<int> order;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, G, states, order)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};


class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<set<int>> G(N);
        vector<int> inDegree(N);
        for (auto p: prerequisites) {
            G[p[1]].insert(p[0]);
            inDegree[p[0]]++;
        }
        set<int> toProcess;
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0) {
                toProcess.insert(i);
            }
        }
        
        vector<int> res;
        while (!toProcess.empty()) {
            int i = *toProcess.begin();
            toProcess.erase(i);
            for (int j: G[i]) {
                inDegree[j]--;
                if (inDegree[j] == 0) {
                    toProcess.insert(j);
                }
            }
            res.push_back(i);
        }     
        
        return res.size() == N ? res : vector<int>{};
        
    }
};



class Solution {
public:
    enum State {
        NotVisited,
        Visiting,
        Visited
    };
    
    bool dfs(vector<vector<int>>& G, int i, vector<State>& states, vector<int>& res) {
        if (states[i] == Visited) {
            return true;
        } else if (states[i] == Visiting) {
            return false;
        }
        
        states[i] = Visiting;
        for (int j: G[i]) {
            if (!dfs(G, j, states, res)) {
                return false;
            }
        }
        res.push_back(i);
        states[i] = Visited;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        
        vector<vector<int>> G(N);
        for (auto p: prerequisites) {
            G[p[1]].push_back(p[0]);
        }
        vector<int> res;
        vector<State> states(N, NotVisited);
        for (int i = 0; i < N; i++) {
            if (!dfs(G, i, states, res)) {
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for (auto p: prerequisites) {
            G[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0) {
                res.push_back(i);
            }
        }
        
        int j = 0;
        while (res.size() != N) {
            if (j >= res.size()) {
                return {};
            }
            int x = res[j];
            j++;
            for (int y: G[x]) {
                inDegree[y]--;
                if (inDegree[y] == 0) {
                    res.push_back(y);
                }
            }
        }
        
        return res;
    }
};

enum State {
    TODO,
    DOING,
    DONE
};

class Solution {
public:
    bool dfs(int i, vector<State>& state, vector<vector<int>>& G, vector<int>& res) {
        if (state[i] == DONE) {
            return true;
        } else if (state[i] == DOING) {
            return false;
        }
        
        state[i] = DOING;
        for (int j: G[i]) {
            if (!dfs(j, state, G, res)) {
                return false;
            }
        }
        state[i] = DONE;
        res.push_back(i);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> G(N);        
        for (auto p: prerequisites) {
            G[p[1]].push_back(p[0]);
        }
        
        vector<int> res;
        vector<State> state(N, TODO);
        for (int i = 0; i < N; i++) {
            if (!dfs(i, state, G, res)) {
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    enum { TO_VISIT, VISITING, VISITED };
    
    bool dfs(int i, map<int, vector<int>>& G, vector<int>& done, vector<int>& res) {
        if (done[i] == VISITING) {
            return false;
        } else if (done[i] == VISITED) {
            return true;
        }
        done[i] = VISITING;
        for (int j: G[i]) {
            if (!dfs(j, G, done, res)) {
                return false;
            }
        }
        res.push_back(i);
        done[i] = VISITED;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        
        int n = numCourses;
        vector<int> done(n, TO_VISIT);
        map<int, vector<int>> G;
        for (auto p: prerequisites) {
            G[p[1]].push_back(p[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!dfs(i, G, done, res)) {
                return {};
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        map<int, vector<int>> G;
        vector<int> inD(n, 0);
        for (auto p: prerequisites) {
            G[p[1]].push_back(p[0]);
            inD[p[0]]++;
        }
        queue<int> todo;
        for (int i = 0; i < n; i++) {
            if (inD[i] == 0) {
                todo.push(i);
            }
        }
        vector<int> res;
        
        while (!todo.empty()) {
            int u = todo.front();
            todo.pop();
            res.push_back(u);
            for (int v: G[u]) {
                inD[v]--;
                if (inD[v] == 0) {
                    todo.push(v);
                }
             }
        }
        
        return res.size() == n ? res : vector<int>{};
    }
};
