// contest
class Solution {
public:
    string replace(string word, set<string>& D) {
        for (int i = 1; i < min(102, int(word.size())); i++) {
            string t = word.substr(0, i);
            if (D.count(t) == 1) {
                return t;
            }
        }
        return word;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        set<string> D(dict.begin(), dict.end());
        
        string ans;
        string word;
        istringstream iss(sentence);
        while (iss >> word) {
            if (!ans.empty()) {
                ans += " ";
            }
            ans += replace(word, D);
        }
        return ans;
    }
};
