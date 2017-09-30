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