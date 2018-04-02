class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<pair<int, int>> points;
        points.push({0, 0});
        for (string op: ops) {
            if (op == "+") {
                pair<int, int> p = points.top();
                points.pop();
                pair<int, int> q = points.top();
                points.push(p);
                int v = p.first + q.first;
                points.push({v, v + p.second});
            } else if (op == "C") {
                points.pop();                
            } else if (op == "D") {
                pair<int, int> p = points.top();
                points.push({p.first * 2, p.second + p.first * 2});
            } else {
                int v = stoi(op);
                points.push({v, points.top().second + v});
            }
        }
        return points.top().second;
    }
};


class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<pair<int, int>> S;
        S.push({0, 0});
        for (string s: ops) {
            if (s == "C") {
                S.pop();
            } else if (s == "D") {
                auto p = S.top();
                S.push({2 * p.first, p.second + 2 * p.first});
            } else if (s == "+") {
                auto p1 = S.top();
                S.pop();
                auto p2 = S.top();
                S.pop();
                S.push(p2);
                S.push(p1);
                int z = p1.first + p2.first;
                S.push({z, z + S.top().second});
            } else {
                int n = stoi(s);
                S.push({n, n + S.top().second});
            }
        }
        return S.top().second;
    }
};