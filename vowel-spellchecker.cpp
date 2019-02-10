class Solution {
public:
    string capNorm(string s) {
        string t;
        for (auto c: s) {
            t.push_back(tolower(c));
        }
        return t;
    }
    
    string voyNorm(string s) {
        string t;
        set<char> voy = {'a', 'e', 'i', 'o', 'u'};
        for (auto c: s) {
            t.push_back(voy.count(tolower(c)) ? '.' : tolower(c));
        }
        return t;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        map<string, string> cap, voy;
        set<string> dict;
        
        for (auto wit = wordlist.rbegin(); wit != wordlist.rend(); wit++) {
            cap[capNorm(*wit)] = *wit;
            voy[voyNorm(*wit)] = *wit;
            dict.insert(*wit);
        }
        
        vector<string> res;
        for (auto q: queries) {
            if (dict.count(q) == 1) {
                res.push_back(q);
            } else if (cap.count(capNorm(q)) == 1) {
                res.push_back(cap[capNorm(q)]);
            } else if (voy.count(voyNorm(q)) == 1) {
                res.push_back(voy[voyNorm(q)]);
            } else {
                res.push_back("");
            }
        }
        
        return res;
    }
};
