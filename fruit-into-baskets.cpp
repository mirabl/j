class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0;
        int lo = 0, hi = 0;
        int n = tree.size();
        while (lo < n) {
            hi = lo;
            int type1 = tree[lo];
            while (hi < n && tree[hi] == type1) {
                hi++;
            }
            int type2 = hi < n ? tree[hi] : -1;
            while (hi < n && (tree[hi] == type2 || tree[hi] == type1)) {
                hi++;
            }
            res = max(res, hi - lo);
            if (hi == n) {
                break;
            }
            lo++;
        }
        return res;
    }
};
