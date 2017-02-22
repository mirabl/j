class Solution {
public:
    bool low(char c) {
        return islower(c) != 0;
    }
    
    bool detectCapitalUse(string word) {
        int start = low(word[0]) ? 0 : 1;
        for (int i = start + 1; i < word.size(); i++) {
            if (low(word[i]) != low(word[start])) {
                return false;
            }
        }
        return true;
    }
};