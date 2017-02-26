class Solution {
public:
    string minWindow(string s, string t) {
        int lo = 0;
        int hi = -1;
        int n = s.size();
        int num_chars = 0;
        string best;
        map<char, int> F;
        set<char> sT;
        for (char c: t) {
            sT.insert(c);
            F[c]++;
        }
        while (lo < n && hi < n) {
            if (num_chars == m) {
                if (best.empty() || hi - lo + 1 < best.size()) {
                    best = s.substr(lo, hi - lo + 1);
                }
                if (sT.count(s[lo]) == 1) {
                    F[s[lo]]++;
                    if (F[s[lo]] > 0) {
                        num_chars--;
                    }
                }
                lo++;
            } else {
                hi++;
                if (sT.count(s[hi]) == 1) {
                    F[s[hi]]--;
                    if (F[s[hi]] == 0) {
                        num_chars++;
                    }
                }
            }
        }
        return best;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int lo = 0;
        int hi = -1;
        int n = s.size();
        int num_chars = 0;
        string best;
        map<char, int> F;
        set<char> sT;
        for (char c: t) {
            sT.insert(c);
            F[c]++;
        }
        int m = sT.size();
        while (lo < n && hi < n) {
            int x;
            int pos;
            if (num_chars == m) {
                if (best.empty() || hi - lo + 1 < best.size()) {
                    best = s.substr(lo, hi - lo + 1);
                }
                pos = lo++;
                x = 1;
            } else {
                pos = ++hi;
                x = -1;
            }
            if (sT.count(s[pos]) == 1) {
                F[s[pos]] += x;
                if (x == 1 && F[s[pos]] > 0) {
                    num_chars--;
                } else if (x == -1 && F[s[pos]] == 0) {
                    num_chars++;
                }
            }
        }
        return best;
    }
};