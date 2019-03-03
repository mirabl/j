class Solution {
public:
    map<char, char> par;
    
    void do_union(char x, char y) {
        par[do_find(x)] = do_find(y);
    }
    
    char do_find(char x) {
        if (par[x] != x) {
            par[x] = do_find(par[x]);
        }
        return par[x];
    }
    
    bool equationsPossible(vector<string>& equations) {
        for (char c = 'a'; c <= 'z'; c++) {
            par[c] = c;
        }
        for (auto eq: equations) {
            char x = eq[0];
            char y = eq[3];
            if (eq[1] == '=') {
                do_union(x, y);
            }
        }
        for (auto eq: equations) {
            char x = eq[0];
            char y = eq[3];
            if (eq[1] == '!') {
                if (do_find(x) == do_find(y)) {
                    return false;
                }
            }
        }
        return true;
    }
};
