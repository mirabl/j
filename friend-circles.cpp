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



// Union find

class Solution {
public:
    void do_init(vector<int>& T) {
        for (int i = 0; i < T.size(); i++) {
            T[i] = i;
        }
    }
    
    // all nodes in path of i now point directly to root of j
    void do_union(vector<int>& T, int i, int j) {
        int rj = do_find(T, j);
        int k = i;
        while (T[k] != rj) {
            int tmp = T[k];
            T[k] = rj;
            k = tmp;
        }
    }
    
    int do_find(vector<int>&  T, int i) {
        int k = i;
        while (T[k] != k) {
            k = T[k];
        }
        return k;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> T(n);
        do_init(T);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] == 1) {
                    do_union(T, i, j);
                }
            }
        }
        unordered_set<int> repr;
        for (int i = 0; i < n; i++) {
            repr.insert(do_find(T, i));
        }
        return repr.size();
    }
};

//

class Solution {
public:
    void do_init(vector<int>& T) {
        for (int i = 0; i < T.size(); i++) {
            T[i] = i;
        }
    }
    
    // Possible optimization: union by rank.
    void do_union(vector<int>& T, int i, int j) {
        int rj = do_find(T, j);
        int ri = do_find(T, i);
        T[ri] = rj;
    }
    
    // Path compression. Now point directly to root.
    int do_find(vector<int>& T, int i) {
        if (T[i] == i) {
            return i;
        } else {
            T[i] = do_find(T, T[i]);
            return T[i];
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> T(n);
        do_init(T);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] == 1) {
                    do_union(T, i, j);
                }
            }
        }
        unordered_set<int> repr;
        for (int i = 0; i < n; i++) {
            repr.insert(do_find(T, i));
        }
        return repr.size();
    }
};

//

class Solution {
public:
    void do_init(vector<int>& T) {
        for (int i = 0; i < T.size(); i++) {
            T[i] = i;
        }
    }
    
    // Possible optimization: union by rank.
    void do_union(vector<int>& T, int i, int j) {
        int rj = do_find(T, j);
        int ri = do_find(T, i);
        T[ri] = rj;
    }
    
    // Path compression. Now point directly to root.
    int do_find(vector<int>& T, int i) {
        if (T[i] == i) {
            return i;
        } else {
            T[i] = do_find(T, T[i]);
            return T[i];
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> T(n);
        do_init(T);
        int res = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] == 1) {
                    if (do_find(T, i) != do_find(T, j)) {
                        res--;
                    }
                    do_union(T, i, j);
                }
            }
        }
        return res;
    }
};