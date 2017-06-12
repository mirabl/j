class StringIterator {
public:
    char c;
    int k;
    int offset;
    string s;
    StringIterator(string compressedString) {
        offset = 0;
        s = compressedString;
        k = 0;
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (k == 0) {
            c = s[offset];
            offset++;
            while (isdigit(s[offset])) {
                k = 10 * k + (s[offset] - '0');
                offset++;
            }
        }
        k--;
        return c;
    }
    
    bool hasNext() {
        return k > 0 || offset < s.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

class StringIterator {
private:
    char c;
    int k;
    int offset;
    string s;
    
public:
    StringIterator(string compressedString): offset(0), s(compressedString), k(0) {
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (k == 0) {
            c = s[offset];
            offset++;
            while (isdigit(s[offset])) {
                k = 10 * k + (s[offset] - '0');
                offset++;
            }
        }
        k--;
        return c;
    }
    
    bool hasNext() {
        return k > 0 || offset < s.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

class StringIterator {
private:
    char c;
    int k = 0;
    istringstream in;

public:
    StringIterator(string compressedString): in(compressedString) {
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (k == 0) {
            in >> c >> k;
        }
        k--;
        return c;
    }
    
    bool hasNext() {
        return k > 0 || !in.eof();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

// https://leetcode.com/problems/design-compressed-string-iterator/#/description