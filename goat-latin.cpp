// contest
class Solution {
public:
    string toGoatLatin(string S) {
        istringstream iss(S);
        string ans;
        string word;
        set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int index = 1;
        while (iss >> word) {
            if (!ans.empty()) {
                ans += " ";
            }
            string s;
            if (vowels.count(tolower(word[0])) == 1) {
                s = word;
            } else {
                s = word.substr(1);
                s = s + word[0];
            }
            s = s + "ma";
            for (int i = 1; i <= index; i++) {
                s = s + "a";
            }
            ans += s;
            index++;
        }
        return ans;
    }
};

