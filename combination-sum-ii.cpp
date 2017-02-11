class Solution {
public:
    void rec(vector<int>& A, int target, int i, vector<int>& prefix, set<vector<int>>& res) {
        if (target == 0) {
            res.insert(prefix);
            return;
        } else if (target < 0) {
            return;
        }
        const int n = int(A.size());
        for (int j = i; j < n; j++) {
            prefix.push_back(A[j]);
            rec(A, target - A[j], j + 1, prefix, res);
            prefix.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> resS;
        vector<int> prefix;
        sort(candidates.begin(), candidates.end());
        rec(candidates, target, 0, prefix, resS);
        vector<vector<int>> res(resS.begin(), resS.end());
        return res;    
    }
};
