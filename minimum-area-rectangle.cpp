// contest
class Solution {
public:
    int area(vector<int>& P, pair<int, int>& Q) {
        return abs(P[0] - Q.first) * abs(P[1] - Q.second);
    }
    
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> PP;
        map<int, vector<vector<int>>> pointsByX;
        for (auto p: points) {
            PP.insert({p[0], p[1]});
            pointsByX[p[0]].push_back(p);
        }
        int INFTY = 1e8;
        int best = INFTY;
        int N = points.size();
        for (auto p: points) {
            for (auto q: points) {
                if (p[1] != q[1] || p[0] == q[0]) {
                    continue;
                }
                for (auto r: pointsByX[p[0]]) {
                    if (r[0] != p[0] || r[1] == p[1]) {
                        continue;
                    }
                    pair<int, int> s{q[0], r[1]};
                    if (PP.count(s) == 1) {
                       // cout << p[0] << " " << p[1] << ", " << q[0] << " " << q[1] << ", " << r[0] << " " << r[1] << ", " << s.first << " " << s.second << endl;
                      //  cout << "       " << area(p, s) << endl;
                        best = min(best, area(p, s));
                    }
                }
            }
        }
        
        return best == INFTY ? 0 : best;
    }
};
