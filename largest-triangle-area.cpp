class Solution {
public:
    double area(vector<int>& p, vector<int>& q, vector<int>& r) {
        return abs((p[0] * (q[1] - r[1])) + (q[0] * (r[1] - p[1])) + (r[0] * (p[1] - q[1]))) / 2.0;
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        for (auto p: points) {
            for (auto q: points) {
                for (auto r: points) {
                    double a = area(p, q, r);
                    maxArea = max(maxArea, a);
                }
            }
        }
        return maxArea;
    }
};
