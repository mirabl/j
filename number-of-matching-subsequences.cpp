class Solution {
public:
    int findPosition2(map<char, vector<int>>& positionByChar, char c, int from) {
        for (int pos: positionByChar[c]) {
            if (pos >= from) {
                return pos;
            }
        }
        return -1;
    }

    int numMatchingSubseq(string S, vector<string>& words) {
        map<char, vector<int>> positionByChar;
        for (int i = 0; i < S.size(); i++) {
            positionByChar[S[i]].push_back(i);
        }
        int res = 0;
        for (auto word: words) {
            int i = 0;
            bool match = true;
            for (int j = 0; j < word.size(); j++) {
                char d = word[j];
                int iMatch = findPosition2(positionByChar, d, i);
                if (iMatch == -1) {
                    match = false;
                    break;
                } 
                i = iMatch + 1;
            }
            if (match) {
                res++;
            }
        }
        return res;
    }
};