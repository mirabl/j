class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int profit = 0;
        int i = 0;
        const int n = int(prices.size());
        while (true) {
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            if (i >= n - 1) {
                break;
            }
            i++;
            profit += prices[i] - prices[i - 1];
            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
                profit += prices[i] - prices[i - 1];
            }
            i++;
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < int(prices.size()) - 1; i++) {
            profit += max(0, prices[i + 1] - prices[i]);
        }
        return profit;
    }
};