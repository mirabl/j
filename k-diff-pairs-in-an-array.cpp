class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        set<int> S;
        set<int> same;
        if (k < 0) {
            return 0;
        }
        for (int x: nums) {
            if (S.count(x) == 1) {
                if (k == 0 && same.count(x) == 0) {
                    res++;
                    same.insert(x);
                }
            } else {
                if (S.count(x + k)) {
                    res++;
                }
                if (S.count(x - k)) {
                    res++;
                }
                S.insert(x);
            }
        }
        return res;
    }
};