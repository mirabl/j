class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> S;
        for (auto c: s) {
            if (!S.empty() && c == S.top()) {
                S.pop();
            } else {
                S.push(c);
            }
        }
        string t;
        while (!S.empty()) {
            t.push_back(S.top());
            S.pop();
        }
        reverse(t.begin(), t.end());
        return t;
    }
};
