class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        map<char, int> char_to_row;
        for (int i = 0; i < int(rows.size()); i++) {
            for (char c: rows[i]) {
                char_to_row[c] = i;
            }
        }
        vector<string> res;
        for (string word: words) {
            set<int> R;
            for (char c: word) {
                R.insert(char_to_row[tolower(c)]);
            }
            if (R.size() == 1) {
                res.push_back(word);
            }
        }
        return res;
    }
};