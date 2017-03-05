class Solution {
public:
    bool isSubSequence(string& s, string& t, int i, int j) {
        if (i == s.size()) {
            return true;
        }
        int k = j;
        while (k < t.size() && s[i] != t[k]) {
            k++;
        }
        return k == t.size() ? false : isSubSequence(s, t, i + 1, k + 1);
    }

    string findLongestWord(string s, vector<string>& d) {
        vector<string> cur;
        int size = 0;
        for (string v: d) {
            if (v.size() >= size && isSubSequence(v, s, 0, 0)) {
                if (v.size() > size) {
                    cur.clear();
                    size = v.size();
                }
                cur.push_back(v);
            }
        }
        sort(cur.begin(), cur.end());
        return cur.empty() ? "" : cur[0];
    }
};

class Solution {
public:
    bool isSubSequence(string& s, string& t) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            while (j < t.size() && t[j] != s[i]) {
                j++;
            }
            if (j < t.size()) {
                i++;
                j++;
            }
        }
        return i == s.size();
    }

    string findLongestWord(string s, vector<string>& d) {
        vector<string> cur;
        int size = 0;
        for (string v: d) {
            if (v.size() >= size && isSubSequence(v, s)) {
                if (v.size() > size) {
                    cur.clear();
                    size = v.size();
                }
                cur.push_back(v);
            }
        }
        sort(cur.begin(), cur.end());
        return cur.empty() ? "" : cur[0];
    }
};

