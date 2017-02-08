class Solution {
public:
    map<pair<int, pair<int, int>>, vector<vector<int>>> memo;

    vector<vector<int>> rec(int S, int i, int k) {
        if (k == 0) {
            if (S == 0) {
                return vector<vector<int>>(1);
            } else {
                return vector<vector<int>>();
            }
        }
        if (memo.count({S, {i, k}}) == 0) {
            vector<vector<int>> res;
            for (int j = i; j < 10; j++) {
                vector<vector<int>> tail = rec(S - j, j + 1, k - 1);
                for (auto v: tail) {
                    v.insert(v.begin(), j);
                    res.push_back(v);
                }
            }
            memo[{S, {i, k}}] = res;
        }
        return memo[{S, {i, k}}];
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        return rec(n, 1, k);
    }
};
// better
// https://discuss.leetcode.com/topic/14641/my-c-solution-backtracking
