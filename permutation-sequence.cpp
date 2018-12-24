/*
https://leetcode.com/problems/permutation-sequence/
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }
        int nminus1fact = 1;
        for (int i = 2; i < n; ++i) {
            nminus1fact *= i;
        }
        int e = 1 + ((k - 1) / nminus1fact);
        // First digit is e
        string s = to_string(e);
        string t = getPermutation(n - 1, 1 + (k - 1) % nminus1fact);
        for (int i = 0; i < int(t.size()); ++i) {
            if (int(t[i] - '0') >= e) {
                t[i] = char(int(t[i] - '0') + 1) + '0';
            }
        }
        return s + t;
    }
};