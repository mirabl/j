class Solution {
public:
    vector<int> diStringMatch(string S) {
        S = "D" + S;        
        int n = S.size();
        vector<int> res(n);
        int v = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (S[i] == 'I') {
                res[i] = v;
                v--;
            }
        }
        v = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (S[i] == 'D') {
                res[i] = v;
                v++;
            }
        }
        
        return res;
    }
};
