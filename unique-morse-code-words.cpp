class Solution {
public:
    string transform(string word) {
        vector<string> letters{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string res;
        for (char c: word) {
            res = res + letters[c - 'a'];
        }
        return res;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> S;
        for (auto word: words) {
            S.insert(transform(word));
        }
        return S.size();
    }
};