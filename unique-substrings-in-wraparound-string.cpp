class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        int lo = 0;
        vector<int> M(26, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0 && p[i] != p[i - 1] + 1 && !(p[i] == 'a' && p[i - 1] == 'z')) {
                lo = i;
            }
            M[p[i] - 'a'] = max(M[p[i] - 'a'], i - lo + 1);
        }
        return accumulate(M.begin(), M.end(), 0);
    }
};