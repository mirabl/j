// contest

class Solution {
public:
    
    void findClosestBefore(string S, char C, vector<int>& ans) {
        int last = -1;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                last = i;
            }
            if (last == -1) {
                continue;
            }
            int d = i - last;
            if (ans[i] == -1 || ans[i] > d) {
                ans[i] = d;
            }
        }
    }
    
    vector<int> shortestToChar(string S, char C) {
        int N = S.size();
        vector<int> ans(N, -1);
        findClosestBefore(S, C, ans);
        reverse(ans.begin(), ans.end());
        reverse(S.begin(), S.end());
        findClosestBefore(S, C, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
