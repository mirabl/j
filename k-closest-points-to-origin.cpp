class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, pair<int, int>>> V;
        for (auto point: points) {
            int x = point[0];
            int y = point[1];
            V.push_back({x*x + y*y, {x, y}});
        }
        sort(V.begin(), V.end());
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            auto q = V[i];
            res.push_back({q.second.first, q.second.second});
        }
        return res;
    }
};
