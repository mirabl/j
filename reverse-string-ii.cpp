class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int j = min(i + k, n);
            for (int l = i; l < i + (j - i) / 2; l++) {
                swap(s[l], s[j - 1 - l + i]);
            }
        }
        return s;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int j = min(i + k, n);
            for (int l = 0; l < (j - i) / 2; l++) {
                swap(s[l + i], s[j - 1 - l]);
            }
        }
        return s;
    }
};
