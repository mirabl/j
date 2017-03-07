class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int, int>> V;
        int N = height.size();
        for (int i = 0; i < N; i++) {
            V.push_back({height[i], i});
        }
        sort(V.begin(), V.end());
        int l = min(V[N - 1].second, V[N - 2].second);
        int r = max(V[N - 1].second, V[N - 2].second);
        int max_v = 0;
        for (int i = N - 2; i >= 0; i--) {
            l = min(l, V[i].second);
            r = max(r, V[i].second);
            int v = V[i].first * (r - l);
            max_v = max(max_v, v);
        }
        return max_v;
    }
};
// better: two pointer solution https://leetcode.com/articles/container-most-water/ O(n)