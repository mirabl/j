class Solution {
public:
    string login(string s) {
        string l;
        for (auto c: s) {
            if (c == '+' || c == '@') {
                break;
            }
            if (c != '.') {
                l.push_back(c);
            }
        }
        return l;
    }
    
    string domain(string s) {
        string d;
        int i = 0;
        while (s[i] != '@') {
            i++;
        }
        i++;
        while (i < s.size()) {
            d.push_back(s[i]);
            i++;
        }
        return d;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        set<pair<string, string>> S;
        for (auto email: emails) {
            auto l = login(email);
            auto d = domain(email);
            S.insert({l, d});
        }
        return S.size();
    }
};
