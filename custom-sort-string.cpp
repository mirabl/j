class Solution {
public:
    string customSortString(string S, string T) {
        string res;
        set<char> Sset;
        for (auto c: S) {
            Sset.insert(c);
        }
        map<char, int> F;
        for (auto c: T) {
            if (Sset.count(c) == 1) {
                F[c]++;
            } else {
                res += c;
            }
        }
        
        for (char c: S) {
            while (F[c] > 0) {
                res += c;
                F[c]--;
            }
        }
        
        return res;
    }
};
