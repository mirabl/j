// TLE

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        queue<int> Q;
        int n = pid.size();
        Q.push(kill);
        while (!Q.empty()) {
            int p = Q.front();
            Q.pop();
            res.push_back(p);
            for (int i = 0; i < n; i++) {
                if (ppid[i] == p) {
                    Q.push(pid[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        queue<int> Q;
        Q.push(kill);
        int n = pid.size();

        map<int, vector<int>> children;
        for (int i = 0; i < n; i++) {
            children[ppid[i]].push_back(pid[i]);
        }

        while (!Q.empty()) {
            int p = Q.front();
            Q.pop();
            res.push_back(p);
            for (int x: children[p]) {
                Q.push(x);
            }
        }
        return res;
    }
};

class Solution {
public:
    void dfs(int pid, map<int, vector<int>>& children, vector<int>& res) {
        res.push_back(pid);
        for (int x: children[pid]) {
            dfs(x, children, res);
        }
    }

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        queue<int> Q;
        Q.push(kill);
        int n = pid.size();

        map<int, vector<int>> children;
        for (int i = 0; i < n; i++) {
            children[ppid[i]].push_back(pid[i]);
        }

        dfs(kill, children, res);
        return res;
    }
};

