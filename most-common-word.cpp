// contest
class Solution {
public:
    vector<string> getWords(string paragraph) {
        vector<string> words;
        string word;
        paragraph.push_back(' ');
        for (char c: paragraph) {
            if (isalpha(c)) {
                word.push_back(tolower(c));
            } else if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        return words;
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words = getWords(paragraph);
        set<string> bannedWords(banned.begin(), banned.end());
        
        map<string, int> countByWord;
        for (string word: words) {
            if (bannedWords.count(word) == 1) {
                continue;
            }
            countByWord[word]++;
        }
        
        string bestWord;
        int maxCount = 0;
        for (auto kvp: countByWord) {
            if (kvp.second > maxCount) {
                maxCount = kvp.second;
                bestWord = kvp.first;
            }
        }
        return bestWord;
    }
};