class Solution {
public:
    void dfs(vector<vector<int>>& M, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] == 1 && !visited[j]) {
                dfs(M, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<bool> visited(N, false);
        int res = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                res++;
                dfs(M, i, visited);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<bool> visited(N, false);
        int res = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                res++;
                queue<int> Q;
                Q.push(i);
                while (!Q.empty()) {
                    int j = Q.front();
                    Q.pop();
                    visited[j] = true;
                    for (int k = 0; k < N; k++) {
                        if (M[j][k] == 1 && !visited[k]) {
                            Q.push(k);
                        }
                    }
                }
            }
        }
        return res;
    }
};

