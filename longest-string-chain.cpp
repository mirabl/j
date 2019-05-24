class Solution {
public:
    bool pred(string& s, string& t) {
        int n = t.size();
        if (t.size() != s.size() + 1) {
            return false;
        }
        int i = 0; 
        int j = 0;
        while (i < n - 1 && s[i] == t[j]) {
            i++;
            j++;
        }

        if (i == n - 1) {
            return true;
        }
        j++;
        
        while (i < n - 1 && j < n) {
            if (s[i] != t[j]) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    
    int l(map<int, vector<int>>& G, int i) {
        int best = 1;
        for (int j: G[i]) {
            best = max(best, 1 + l(G, j));
        }
        return best;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        map<int, vector<int>> G;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pred(words[i], words[j])) {
                    G[i].push_back(j);
                }
            }
        }
        
        int b = 0;
        for (int i = 0; i < n; i++) {
            b = max(b, l(G, i));
        }
        
        return b;
    }
};
