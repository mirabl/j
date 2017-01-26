class Solution {
public:
    void rec(vector<int>& A, int i, set<vector<int>>& res) {
        if (i < 0) {
            return;
        }
        int x = A[i];
        rec(A, i - 1, res);
        set<vector<int>> tmp;
        for (auto v: res) {
            auto w(v);
            w.push_back(x);
            sort(w.begin(), w.end());
            tmp.insert(w);
        }
        res.insert(tmp.begin(), tmp.end());
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> S;
        S.insert(vector<int>());
        rec(nums, int(nums.size()) - 1, S);
        vector<vector<int>> res;
        for (auto x: S) {
            res.push_back(x);
        }
        return res;
    }
};