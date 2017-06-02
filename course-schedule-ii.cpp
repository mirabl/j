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