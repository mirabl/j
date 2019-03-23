class Solution {
public:
    bool isValid(string S) {
        stack<char> T;
        for (auto c: S) {
            if (c == 'a') {
                T.push(c);
            } else if (c == 'b') {
                if (!T.empty() && T.top() == 'a') {
                    T.push(c);
                } else {
                    return false;
                }
            } else if (c == 'c') {
                if (!T.empty() && T.top() == 'b') {
                    T.pop();
                    if (!T.empty() && T.top() == 'a') {
                        T.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        
        return T.empty();
    }
};
