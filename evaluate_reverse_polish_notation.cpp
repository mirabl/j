/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int x = S.top();
                S.pop();
                int y = S.top();
                S.pop();
                if (token == "+") {
                    S.push(x + y);
                } else if (token == "-") {
                    S.push(y - x);
                } else if (token == "*") {
                    S.push(x * y);
                } else if (token == "/") {
                    S.push(y / x);
                }
            } else {
                S.push(stoi(token));
            }
        }
        return S.top();
    }
};