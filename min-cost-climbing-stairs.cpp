class Solution {
public:
    int min_rec(vector<int>& cost, int start, vector<int>& memo) {
        if (start >= cost.size()) {
            return 0;
        }
        if (memo[start] == -1) {
            memo[start] = cost[start] + min(min_rec(cost, start + 1, memo), min_rec(cost, start + 2, memo));
        }
        return memo[start];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(1000 + 1, -1);
        return min(min_rec(cost, 0, memo), min_rec(cost, 1, memo));
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = 0;
        int y = 0;
        for (int i = cost.size() - 1; i >= 0; i--) {
            int t = cost[i] + min(x, y);
            y = x;
            x = t;
        }
        return min(x, y);
    }
};

