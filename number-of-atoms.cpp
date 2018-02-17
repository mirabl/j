class Solution {
public:
    int findClosingParen(string& s, int start) {
        int o = 0;
        int pos = start + 1;
        while (!(o == 0 && s[pos] == ')')) {
            if (s[pos] == '(') {
                o++;
            } else if (s[pos] == ')') {
                o--;
            }
            pos++;
        }
        return pos;
    }

    int readCount(string s, int start, int& next_offset) {
        int count = 0;
        int pos = start;
        while (pos < s.size() && isdigit(s[pos])) {
            count = count * 10 + (s[pos] - '0');
            pos++;
        }
        next_offset = pos;
        return count > 0 ? count : 1;
    }
    
    void merge(map<string, int>& A, const map<string, int>& B, int factor) {
        for (auto p: B) {
            A[p.first] += factor * p.second;
        }
    }
    
    map<string, int> parse(string s) {
        int pos = 0;
        map<string, int> freq;
        while (pos != s.size()) {
            if (s[pos] == '(') {
                int closing_paren_offset = findClosingParen(s, pos);
                string t = s.substr(pos + 1, closing_paren_offset - (pos + 1));
                pos = closing_paren_offset + 1;
                merge(freq, parse(t), readCount(s, pos, pos));
            } else {
                string element;
                int count;
                getNextElement(s, pos, element, count, pos);
                freq[element] += count;
            }

        }
        return freq;
    }
    
    void getNextElement(string s, int start, string& element, int& count, int& next_offset) {
        int pos = start;
        while (pos < s.size() && (pos == start || islower(s[pos]))) {
            element += s[pos];
            pos++;
        }
        count = readCount(s, pos, next_offset);
    }
    
    string countsToString(map<string, int>& counts) {
        vector<pair<string, int>> V;
        for (auto p: counts) {
            V.push_back({p.first, p.second});
        }
        sort(V.begin(), V.end());
        string s = "";
        for (auto p: V) {
            s += p.first + (p.second > 1 ? to_string(p.second) : "");
        }
        return s;
    }
    
    string countOfAtoms(string formula) {
        map<string, int> counts = parse(formula);
        return countsToString(counts);
    }
};

// 

class Solution {
public:
    typedef map<string, int> freq_t;
    
    string getTokenInsideParen(string& s, int start, int& next_offset) {
        int o = 0;
        int pos = start + 1;
        while (!(o == 0 && s[pos] == ')')) {
            if (s[pos] == '(') {
                o++;
            } else if (s[pos] == ')') {
                o--;
            }
            pos++;
        }
        next_offset = pos + 1;
        return s.substr(start + 1, pos - start - 1);
    }

    int getCount(string s, int start, int& next_offset) {
        int count = 0;
        int pos = start;
        while (pos < s.size() && isdigit(s[pos])) {
            count = count * 10 + (s[pos] - '0');
            pos++;
        }
        next_offset = pos;
        return count > 0 ? count : 1;
    }
    
    freq_t getNextElement(string s, int start, int& next_offset) {
        int pos = start;
        string element;
        while (pos < s.size() && (pos == start || islower(s[pos]))) {
            element += s[pos];
            pos++;
        }
        next_offset = pos;
        return {{ element, 1 }};
    }
    
    void merge(freq_t& A, const freq_t& B, int factor) {
        for (auto p: B) {
            A[p.first] += factor * p.second;
        }
    }
    
    freq_t parse(string s) {
        int pos = 0;
        freq_t freq;
        while (pos != s.size()) {
            freq_t sub_freq;
            if (s[pos] == '(') {
                sub_freq = parse(getTokenInsideParen(s, pos, pos));
            } else {
                sub_freq = getNextElement(s, pos, pos);
            }
            merge(freq, sub_freq, getCount(s, pos, pos));
        }
        return freq;
    }
   
    string countsToString(freq_t& counts) {
        vector<pair<string, int>> V;
        for (auto p: counts) {
            V.push_back({p.first, p.second});
        }
        sort(V.begin(), V.end());
        string s = "";
        for (auto p: V) {
            s += p.first + (p.second > 1 ? to_string(p.second) : "");
        }
        return s;
    }
    
    string countOfAtoms(string formula) {
        map<string, int> counts = parse(formula);
        return countsToString(counts);
    }
};