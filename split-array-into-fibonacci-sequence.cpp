class Solution {
public:
    int toInt(string s) {
        if (s.size() >= 11 || (s.size() > 1 && s[0] == '0')) {
            return -1;
        }
        return stol(s);
    }
    
    bool tryComplete(string S, vector<int>& v, int from) {
        if (from == S.size()) {
            return true;
        }
        int next = v[v.size() - 1] + v[v.size() - 2];
        string snext = to_string(next);
        if (S.substr(from, snext.size()) == snext) {
            v.push_back(next);
            return tryComplete(S, v, from + snext.size());
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        int N = int(S.size());
        for (int i = 0; i < N - 2; i++) {
            string sx = S.substr(0, i + 1); // [0...i]
            int x = toInt(sx);
            if (x < 0) {
                continue;
            }

            for (int j = i + 1; j < N - 1; j++) { // [i+1...j]
                string sy = S.substr(i + 1, j - i);
                int y = toInt(sy);
                if (y < 0) {
                    continue;
                }
                
                vector<int> v{x, y};
                if (tryComplete(S, v, j + 1)) {
                    return v;
                }
            }
        }
        return {};
    }
};
