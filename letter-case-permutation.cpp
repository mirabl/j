class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res{""};
        for (char c: S) {
            vector<char> C;
            if (isalpha(c)) {
                C.push_back(tolower(c));
                C.push_back(toupper(c));
            } else {
                C.push_back(c);
            }
            vector<string> V;
            for (string t: res) {
                for(char d: C) {
                    V.push_back(t + d);
                }
            }
            res = V;
        }
        return res;
    }
};
