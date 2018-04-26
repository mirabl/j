// contest
class Solution {
public:
    set<pair<int, int>> S;
    
    bool isPalindrome(int j, int i) {
        return j > i || S.count({i, j}) == 1;
    }
    
    void setPalindrome(int j, int i) {
        S.insert({i, j});
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // [i, j]
            for (int j = 0; j <= i; j++) {
                string t = s.substr(j, i - j + 1);
                if (s[i] == s[j] && isPalindrome(j + 1, i - 1)) {
                    setPalindrome(j, i);
                }
            }
        }
        return S.size();
    }
};
