class Solution {
public:
    bool isDigit(string cont) {
        for (char c: cont) {
            if (c == ' ') {
                continue;
            }
            return !isalpha(c);
        }
        return false; // NR
    }
    
    pair<string, string> split(string s) {
        string ident, cont;
        int pos = 0;
        while (s[pos] != ' ') {
            ident.push_back(s[pos]);
            pos++;
        }
        
        pos++;
        while (pos < s.size()) {
            cont.push_back(s[pos]);
            pos++;
        }
        
        return {ident, cont};
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<pair<string, string>, string>> letSplit;
        vector<string> dig;
        for (auto log: logs) {
            auto p = split(log);
            auto ident = p.first;
            auto cont = p.second;
            //cout << "id=" << ident << " cnt=" << cont << endl;
            if (isDigit(cont)) {
              //  cout << "  dig " << endl;
                dig.push_back(log);
            } else {
                letSplit.push_back({{cont, ident}, log});
            }
        }
        sort(letSplit.begin(), letSplit.end());
        vector<string> res;
        for (auto x: letSplit) {
            res.push_back(x.second);
        }
        for (auto x: dig) {
            res.push_back(x);
        }
        return res;
    }
};
