/*
https://leetcode.com/problems/combination-sum/
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<set<vector<int>>> S(target + 1);
        S[0].insert(vector<int>());
        for (int x = 1; x < target + 1; x++) {
            for (int c: candidates) {
                if (x - c >= 0) {
                    for (vector<int> v: S[x - c]) {
                        v.push_back(c);
                        sort(v.begin(), v.end());
                        S[x].insert(v);
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (auto x: S[target]) {
            res.push_back(x);
        }
        return res;
    }
};