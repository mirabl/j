class Solution {
public:
    bool can(string lo, string hi, map<string, vector<char>>& blocks) {
        if (lo.size() <= 1) {
            return true;
        }
        int i = hi.size();
        if (i == lo.size() - 1) {
            return can(hi, "", blocks);
        }
        
        for (char c: blocks[lo.substr(i, 2)]) {
            hi.push_back(c);
            if (can(lo, hi, blocks)) {
                return true;
            }
            hi.pop_back();
        }
        
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, vector<char>> blocks;
        for (string s: allowed) {
            blocks[s.substr(0, 2)].push_back(s[2]);
        }
        return can(bottom, "", blocks);
    }
};