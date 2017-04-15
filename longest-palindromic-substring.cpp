class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res(s.substr(0, 1));
        vector<bool> A(n, true);
        vector<bool> B(n, true);
        for (int l = 2; l < n + 1; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                 A[i] = B[i];
                 B[i] = s[i] == s[i + l - 1] && A[i + 1];
                if (B[i]) {
                    res = s.substr(i, l);
                }
            }
        }
        return res;
    }
};


// O(n^2) but no space
// http://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
// straightforward, iterate through string, take each char as starting point and expand for even-length and odd-length palindrome

// Manacher's algorithm O(n)
// http://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/