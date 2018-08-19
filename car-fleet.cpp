class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int res = 0;

        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({position[i], speed[i]});
        }
        sort(p.begin(), p.end());
        
        double u = -1;
        for (int i = n - 1; i >= 0; i--) {
            int pos = p[i].first;
            int spe = p[i].second;
            double t = double(target - pos) / double(spe);
            if (t > u) {
                res++;
            } 
            u = max(u, t);
        }
        
        return n > 0 ? res : 0;
    }
};
