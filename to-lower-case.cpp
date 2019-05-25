class Solution {
public:
    string toLowerCase(string str) {
        string t;
        for (auto c: str) {
            t.push_back(tolower(c));
        }
        return t;
    }
};
