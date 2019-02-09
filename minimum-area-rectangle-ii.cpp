class Solution {
public:
    double eps = 1e-4;
    pair<double, double> u, v;
    
    pair<double,double> d(vector<int>& a, vector<int>& b) {
        return {b[0] - a[0], b[1] - a[1]};
    }
    
    bool isRight(vector<int>& a, vector<int>& b, vector<int>& c) {
        if (eq(a, b) || eq(a, c) || eq(b, c)) {
            return false;
        } 
        
        u = d(a, b);
        v = d(b, c);
        return abs(double(u.first) * double(v.first) + double(u.second) * double(v.second)) < eps;
    }
    
    bool eq(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] && a[1] == b[1];
    }
    
    bool isRect(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        if (eq(a, b) || eq(a, c) || eq(a, d) || eq(b, c) || eq(b, d) || eq(c, d)) {
            return false;
        } 
        
        return isRight(a, b, c) && isRight(b, c, d) && isRight(c, d, a); 
    }
    
    double seglen(vector<int>& a, vector<int>& b) {
        return sqrt(double(b[0] - a[0]) * double(b[0] - a[0]) + double(b[1] - a[1]) * double(b[1] - a[1]));
    }

    double area(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        return seglen(a, b) * seglen(b, c);
    }

    double minAreaFreeRect(vector<vector<int>>& points) {
        double ans = 1e11;
        
        set<pair<int, int>> Q;
        for (auto p: points) {
            Q.insert({p[0], p[1]});
        }
        
        for (auto a: points) {
            for (auto b: points) {
                for (auto c: points) {
                    if (!isRight(a, b, c)) {
                        continue;
                    }
                    
                    pair<int,int> d = {a[0] + c[0] - b[0], a[1] + c[1] - b[1]};
                    if (Q.count(d) == 0) {
                        continue;
                    }
                    vector<int> dd = {d.first, d.second};
                    double v = area(a, b, c, dd);
                    ans = min(ans, v);
                }
            }
        }
        return ans != 1e11 ? ans : 0;
    }
};
