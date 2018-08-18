class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.size();
        string res(n, 0);
        int t = 0;
        for (int i = n - 1; i >= 0; i--) {
            t = (t + shifts[i]) % 26;
            res[i] = (((S[i] - 'a') + t) % 26) + 'a';
        }
        return res;
    }
};
