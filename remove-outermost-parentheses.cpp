class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        if (S.empty()) {
            return "";
        }
        
        int N = S.size();
        int lo = 0;
        int c = 1;
        int hi = 1;
        while (lo < N) {
            if (S[hi] == '(') {
                c++;
            } else {
                c--;
            }
            if (c == 0) {
                res += S.substr(lo + 1, hi - lo - 1);
                lo = hi + 1;
                c = 1;
                hi = lo + 1;
            } else {
                hi++;
            }
        }
        return res;
    }
};
