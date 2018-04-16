// contest
class Solution {
public:
    vector<pair<char, int>> countLetters(string s) {
        vector<pair<char, int>> C;
        char last_char = '!';
        for (char c: s) {
            if (c == last_char) {
                C[C.size() - 1].second++;
            } else {
                C.push_back({c, 1});
            }
            last_char = c;
        }
        return C;
    }

    bool isMatch(vector<pair<char, int>>& cS, vector<pair<char, int>>& cW) {
        if (cW.size() != cS.size()) {
            return false;
        }
        for (int i = 0; i < cW.size(); i++) {
            auto pS = cS[i];
            auto pW = cW[i];
            if (pS.first != pW.first) {
                return false;
            }
            if (pS.second < 3 && pS.second != pW.second) {
                return false;
            } else if (pS.second >= 3 && pS.second < pW.second){
                return false;
            }
        }
        return true;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        auto cS = countLetters(S);
        int res = 0;
        for (auto word: words) {
            auto cW = countLetters(word);
            if (isMatch(cS, cW)) {
                res++;
            }
        }
        return res;
    }
};