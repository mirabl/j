// contest
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int, int>> V;
        for (auto v: pairs) {
            V.push_back({v[1], v[0]});
        }
        sort(V.begin(), V.end());
        vector<pair<int, int>> W;
        for (auto p: V) {
            W.push_back({p.second, p.first});
        }
        int ans = 0;
        pair<int, int> last;
        for (auto p: W) {
            if (ans == 0 || last.second < p.first) {
                last = p;
                ans++;
            }
        }
        return ans;
    }
};
