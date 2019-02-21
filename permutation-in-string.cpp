class Solution {
public:
    bool c(map<char, int>& A, map<char, int>& B) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (A[c] != B[c]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (m < n) {
            return false;
        }
        map<char, int> H1;
        for (auto c: s1) {
            H1[c]++;
        }
        map<char, int> H2;
        for (int i = 0; i < n; i++) {
            H2[s2[i]]++;
        }
        for (int i = n; i < m; i++) {
            if (c(H1, H2)) {
                return true;
            }
            H2[s2[i - n]]--;
            H2[s2[i]]++;
        }
        
        return c(H1, H2);
    }
};
