// contest

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        difficulty.insert(difficulty.begin(), -1);
        profit.insert(profit.begin(), 0);
        difficulty.push_back(1e6);
        profit.push_back(-1);
        int N = difficulty.size();

        vector<pair<int, int>> V;
        for (int i = 0; i < N; i++) {
            V.push_back({difficulty[i], profit[i]});
        }
        sort(V.begin(), V.end());
        difficulty.clear();
        profit.clear();
        for (auto p: V) {
            difficulty.push_back(p.first);
            profit.push_back(p.second);
        }

        int ans = 0;
        int i = 0;
        int maxProfitUntilNow = 0;
        for (int ability: worker) {
//cout << "ability " << ability << endl;
            while (i < N && ability >= difficulty[i]) {
//cout << "i=" << i << endl;
                maxProfitUntilNow = max(maxProfitUntilNow, profit[i]);
                i++;
            } 
            ans += maxProfitUntilNow;
        }
        return ans;
    }
};
