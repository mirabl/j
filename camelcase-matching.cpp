class Solution {
public:
    bool rec(string& q, string& p, int i, int j) {
        int n = q.size();
        int m = p.size();
        if (i == n) {
            return j == m;
        }
        if (isupper(q[i])) {
            return q[i] == p[j] && rec(q, p, i + 1, j + 1);
        } else {
            return (q[i] == p[j] && rec(q, p, i + 1, j + 1)) || rec(q, p, i + 1, j);
        }
    }
    
    bool match(string& q, string& p) {
        return rec(q, p, 0, 0);
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto q: queries) {
            res.push_back(match(q, pattern));
        }
        return res;
    }
};
