// contest
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> suffixes;
        int ans = 0;

        for (int len = 7; len >= 1; len--) {
            for (auto word: words) {
                if (word.size() != len) {
                    continue;
                }
                if (suffixes.count(word) == 1) {
                    continue;
                }
                ans += word.size() + 1;
                for (int pos = 0; pos < word.size(); pos++) {
                    string substring = word.substr(pos);
                    suffixes.insert(substring);
                }
            }
        }
        return ans;
    }
};

