class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string w;
            while (i < n && s[i] != ' ') {
                w.push_back(s[i]);
                i++;
            }
            reverse(w.begin(), w.end());
            res += w + (i < n ? " ": "");
        }
        return res;
    }
};