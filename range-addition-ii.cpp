class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty()) {
            return m * n;
        }
        int min_a = ops[0][0];
        int min_b = ops[0][1];
        for (auto v: ops) {
            min_a = min(min_a, v[0]);
            min_b = min(min_b, v[1]);
        }
        return min_a * min_b;
    }
};

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_a = m;
        int min_b = n;
        for (auto v: ops) {
            min_a = min(min_a, v[0]);
            min_b = min(min_b, v[1]);
        }
        return min_a * min_b;
    }
};

