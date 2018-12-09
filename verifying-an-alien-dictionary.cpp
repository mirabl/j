class Solution {
public:
    map<char, int> pos;
    
    bool isBefore(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        
        int i = 0;
        int j = 0;
        while (i < n || j < m) {
            if (i == n) {
                return true;
            }
            if (j == m) {
                return false;
            }
            if (pos[s[i]] > pos[t[i]]) {
                return false;
            } else if (pos[s[i]] < pos[t[i]]) {
                return true;
            }
            i++;
            j++;
        }
        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            pos[order[i]] = i;
        }
        
        for (int i = 0; i < int(words.size()) - 1; i++) {
            if (!isBefore(words[i], words[i + 1])) {
                return false;
            }
        }
    
        return true;
    }
};
