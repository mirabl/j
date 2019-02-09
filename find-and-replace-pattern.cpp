class Solution {
public:
    string patternize(string& s) {
        map<char, char> oldToNew;
        char cur = 'a';
        string t;
        for (char c: s) {
            if (oldToNew.count(c) == 0) {
                oldToNew[c] = cur;
                cur++;
            }
            t.push_back(oldToNew[c]);
        }
        return t;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto pp = patternize(pattern);
        vector<string> res;
        for (auto w: words) {
            if (patternize(w) == pp) {
                res.push_back(w);
            }
        }
        return res;
    }
};
