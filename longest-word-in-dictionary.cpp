class Solution {
public:
    bool valid(string word, set<string>& words) {
        for (int i = 1; i < word.size(); i++) {
            if (words.count(word.substr(0, i)) == 0) {
                return false;
            }
        }
        return true;
    }
    
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> dic(words.begin(), words.end());
        string res;
        for (string word: words) {
            if (valid(word, dic) && word.size() > res.size()) {
                res = word;
            }
        }
        return res;
    }
};