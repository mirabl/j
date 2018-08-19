class Solution {
public:
    int scoreOfParentheses(string S) {
        int pos = 1;
        int numOpen = 1;
        while (numOpen > 0) {
            if (S[pos] == ')') {
                numOpen--;
            } else {
                numOpen++;
            }
            pos++;
        }
        pos--;
        string left = S.substr(0, pos + 1);
        
        int sr = pos + 1 < S.size() ? scoreOfParentheses(S.substr(pos + 1)) : 0;
        int sl = 0;
        if (left == "()") {
            sl = 1;
        } else {
            string middleLeft = left.substr(1, left.size() - 2);
            sl = 2 * scoreOfParentheses(middleLeft);
        } 
        return sl + sr;
    }
};
