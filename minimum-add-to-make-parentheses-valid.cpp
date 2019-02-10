class Solution {
public:
    int minAddToMakeValid(string S) {
        int numOpen = 0;
        int ans = 0;
        for (auto c: S) {
            if (c == ')') {
                if (numOpen == 0) {
                    ans++;
                } else {
                    numOpen--;
                }
            } else if (c == '(') {
                numOpen++;
            }
        }
        ans += numOpen;
        
        return ans;
    }
};
