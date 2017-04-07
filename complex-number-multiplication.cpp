class Solution {
public:
    pair<int, int> parseComplex(string a) {
        int x = 0;
        int i = 0;
        bool negative = false;
        if (a[i] == '-') {
            negative = true;
            i++;
        }
        while (a[i] != '+') {
            x = x * 10 + (a[i] - '0');
            i++;
        }
        if (negative) {
            x = - x;
        }
        i++;
        int y = 0;
        negative = false;
        if (a[i] == '-') {
            negative = true;
            i++;
        }
        while (a[i] != 'i') {
            y = y * 10 + (a[i] - '0');
            i++;
        }
        if (negative) {
            y = - y;
        }
        return {x, y};
    }

    string complexNumberMultiply(string a, string b) {
        pair<int, int> z1 = parseComplex(a);
        pair<int, int> z2 = parseComplex(b);
        int x = z1.first * z2.first - z1.second * z2.second;
        int y = z1.first * z2.second + z1.second * z2.first;
        return to_string(x) + "+" + to_string(y) + "i";
    }
};  


class Solution {
public:
    pair<int, int> parseComplex(string a) {
        int plus = find(a.begin(), a.end(), '+') - a.begin();
        int x = stoi(a.substr(0, plus));
        int y = stoi(a.substr(plus + 1, a.size() - 1 - plus));
        return {x, y};
    }

    string complexNumberMultiply(string a, string b) {
        pair<int, int> z1 = parseComplex(a);
        pair<int, int> z2 = parseComplex(b);
        int x = z1.first * z2.first - z1.second * z2.second;
        int y = z1.first * z2.second + z1.second * z2.first;
        return to_string(x) + "+" + to_string(y) + "i";
    }
};

class Solution {
public:
    pair<int, int> parseComplex(string a) {
        int plus = a.find('+');
        int x = stoi(a.substr(0, plus));
        int y = stoi(a.substr(plus + 1, a.size() - 1 - plus));
        return {x, y};
    }

    string complexNumberMultiply(string a, string b) {
        pair<int, int> z1 = parseComplex(a);
        pair<int, int> z2 = parseComplex(b);
        int x = z1.first * z2.first - z1.second * z2.second;
        int y = z1.first * z2.second + z1.second * z2.first;
        return to_string(x) + "+" + to_string(y) + "i";
    }
};

