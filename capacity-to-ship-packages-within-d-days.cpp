class Solution {
public:
    int best = -1;
    
    bool test(vector<int>& w, int D, int c) {
        int i = 0;
        int n = w.size();
        for (int d = 0; d < D; d++) {
            int cur = 0;
            while (i < n && cur + w[i] <= c) {
                cur += w[i];
                i++;
            }
        }
        return i == n;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int lo = 1;
        int hi = weights.size() * (*max_element(weights.begin(), weights.end()));
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (test(weights, D, mid)) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return best;
    }
};
