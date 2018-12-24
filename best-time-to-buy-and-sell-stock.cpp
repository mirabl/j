class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int profit = 0;
        const int n = int(prices.size());
        vector<int> maxfrom(n, prices[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            maxfrom[i] = max(maxfrom[i + 1], prices[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            profit = max(profit, maxfrom[i + 1] - prices[i]);
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        const int n = int(prices.size());
        int profit = 0;
        int maxfrom = 0;
        for (int i = n - 1; i >= 0; i--) {
            profit = max(profit, maxfrom - prices[i]);
            maxfrom = max(maxfrom, prices[i]);
        }
        return profit;
    }
};