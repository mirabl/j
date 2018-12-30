class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int kBound = 100 * 100;
        vector<vector<int>> D(N, vector<int>(N, kBound));
        for (vector<int>& v: times) {
            D[v[0] - 1][v[1] - 1] = v[2];
        }
        for (int i = 0; i < N; i++) {
            D[i][i] = 0;
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
        int res = D[K - 1][0];
        for (int i = 1; i < N; i++) {
            res = max(res, D[K - 1][i]);
        }
        
        return res < kBound ? res : -1;
    }
};

// dijkstra
class Solution {
public:
    vector<int> dFromS;
    vector<vector<pair<int, int>>> G;
    int infty = 1e8;
    int N;
    
    
    void dijkstra(int s) {
        set<int> processed{s};

        dFromS[s] = 0;
        int nextU = s;

        while (processed.size() != N) {
            for (auto x: G[nextU]) {
                dFromS[x.first] = min(dFromS[x.first], dFromS[nextU] + x.second);
            }
            processed.insert(nextU);
            nextU = -1;
            for (int u = 0; u < N; u++) {
                if (processed.count(u) == 1) {
                    continue;
                }
                if (nextU == -1 || dFromS[u] < dFromS[nextU]) {
                    nextU = u;
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int _N, int K) {
        N = _N;
        dFromS = vector<int>(N, infty);
        G = vector<vector<pair<int, int>>>(N);
        for (auto time: times) {
            G[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        
        dijkstra(K - 1);
        
        int res = *max_element(dFromS.begin(), dFromS.end());
        return res != infty ? res : -1;
    }
};

// simple dfs
class Solution {
public:
    vector<int> dFromS;
    vector<vector<pair<int, int>>> G;
    int infty = 1e8;
    int N;
    
    void dfs(int t, int d) {
        if (dFromS[t] <= d) {
            return;
        }
        dFromS[t] = d;
        for (auto x: G[t]) {
            dfs(x.first, d + x.second);
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int _N, int K) {
        N = _N;
        dFromS = vector<int>(N, infty);
        G = vector<vector<pair<int, int>>>(N);
        for (auto time: times) {
            G[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
 
        dfs(K - 1, 0);
        int res = *max_element(dFromS.begin(), dFromS.end());
        return res != infty ?  res : -1;
    }
};


class Solution {
public:
    int infty = 1e8;
    vector<int> dist;
    vector<bool> done;
    vector<vector<pair<int, int>>> G;
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        dist = vector<int>(N, infty);
        done = vector<bool>(N, false);
        G = vector<vector<pair<int, int>>>(N);
        for (auto e: times) {
            G[e[0] - 1].push_back({e[1] - 1, e[2]});
        }
        K--;
        dist[K] = 0;
        done[K] = true;
        for (auto e: G[K]) {
            dist[e.first] = e.second;
        }
        
        for (int j = 0; j < N - 1; j++) {
            int nextNode = -1;
            for (int i = 0; i < N; i++) {
                if (!done[i] && (nextNode == -1 || dist[i] < dist[nextNode])) {
                    nextNode = i;
                }
            }
            if (nextNode == -1) {
                break;
            }
            for (auto e: G[nextNode]) {
                int v = e.first;
                dist[v] = min(dist[v], dist[nextNode] + e.second);
            } 
            done[nextNode] = true;
        }
        
        int mx = 0;
        for (int i = 0; i < N; i++) {
            mx = max(mx, dist[i]);
        }
        return mx < infty ? mx : -1;
    }
};

class Solution {
public:
    int infty = 1e6;
    vector<int> dist;
    vector<vector<pair<int, int>>> G;
    void dfs(int src, int w) {
        if (dist[src] <= w) {
            return;
        }
        dist[src] = w;
        for (auto n: G[src]) {
            dfs(n.first, w + n.second);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        dist = vector<int>(N, infty);
        G = vector<vector<pair<int, int>>>(N);
        for (auto e: times) {
            G[e[0] - 1].push_back({e[1] - 1, e[2]});
        }
        dfs(K - 1, 0);
        int mx = dist[0];
        for (int i = 1; i < N; i++) {
            mx = max(mx, dist[i]);
        }
        return mx < infty ? mx : -1;
    }
};
