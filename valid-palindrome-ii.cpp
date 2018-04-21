
// contest
class Solution {
public:
    bool isPalindrome(string s) {
        string t(s.rbegin(), s.rend());
        return s == t;
    }
    
    int findFirstDiff(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return i;
            }
        }
        return -1; // not reached
    }
    
    bool validPalindrome(string s) {
        if (isPalindrome(s)) {
            return true;
        }
        // a b c d b a
        // 0 1 2 3 4 5
        // i = 2
        // a b   d b a
        // a b c   b a
        int i = findFirstDiff(s);
        string t = s.substr(0, i) + s.substr(i + 1);
        string sR(s.rbegin(), s.rend());
        string u = sR.substr(0, i) + sR.substr(i + 1);
        // cout << "t= " << t << endl; cout << "u= " << u << endl;
        return isPalindrome(t) || isPalindrome(u);
    }
};
