
 // contest
 // rewrite with int
 // ugly:)
 class Solution {
public:
    map<pair<string, int>, bool> cache;
    
    
    bool rec(string s, int pos, stack<char>& S) {
        
        
      //  cout << "rec " << s << " " << pos << endl; 
        if (pos >= s.size()) {
            //cout << "\t empty" << endl;
            return S.empty();
        }

        pair<string, int> key = {s.substr(pos), S.size()};
        if (cache.count(key) == 0) {
            char c = s[pos];
            if (c == '(') {
                S.push(c);
                if (rec(s, pos + 1, S)) {
                    cache[key] = true; return cache[key];
                }
                S.pop();
                cache[key] = false; return cache[key];
            }

            if (c == ')') {
                //cout << "\t (" << endl;
                if (S.empty()) {
                    //cout << "\t e " << endl;
                    cache[key] = false; return cache[key];
                }
                if (S.top() == '(') {
                    S.pop();
                    //cout << "\t f " << endl;
                    if (rec(s, pos + 1, S)) {
                        cache[key] = true; return cache[key];
                    }
                    S.push('(');
                    cache[key] = false; return cache[key];
                }
            }

            if (c == '*') {
                if (rec(s, pos + 1, S)) {
                    cache[key] = true; return cache[key];
                }
                s[pos] = '(';
                if (rec(s, pos, S)) {
                    cache[key] = true; return cache[key];
                }
                s[pos] = ')';
                if (rec(s, pos, S)) {
                    cache[key] = true; return cache[key];
                }
            }
            cache[key] = false; // not reached
        }
        return cache[key];
    }
    
    bool checkValidString(string s) {
        stack<char> S;
        return rec(s, 0, S);
    }
};
