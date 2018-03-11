class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> S;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!S.empty() && temperatures[S.top()] <= temperatures[i]) {
                S.pop();
            }
            if (!S.empty()) {
                res[i] = S.top() - i;
            }
            S.push(i);
        }
        return res;
    }
};