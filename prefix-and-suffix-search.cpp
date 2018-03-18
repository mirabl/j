class WordFilter {
public:
    vector<string> words_;
    map<string, vector<int>> byPrefix;
    map<string, vector<int>> bySuffix;
    
    WordFilter(vector<string> words) {
        words_ = words;
        
        for (int word_index = words.size() - 1; word_index >= 0; word_index--) {
            string word = words[word_index];
            for (int i = 0; i <= word.size(); i++) {
                string prefix = word.substr(0, i);
                byPrefix[prefix].push_back(word_index);
            }
            for (int i = 0; i <= word.size(); i++) {
                string suffix = word.substr(word.size() - i, i);
                bySuffix[suffix].push_back(word_index);
            }
       }
    }
    
    int firstDoubleMatch(vector<int>& A, vector<int>& B) {
        int iA = 0;
        int iB = 0;
        while (iA < A.size() && iB < B.size()) {
            if (A[iA] == B[iB]) {
                return A[iA];
            } else if (A[iA] < B[iB]) {
                iB++;
            } else {
                iA++;
            }
        }
        return -1;
    }
    
    int f(string prefix, string suffix) {
        auto matchedPrefix = byPrefix[prefix];
        auto matchedSuffix = bySuffix[suffix];
        return firstDoubleMatch(matchedPrefix, matchedSuffix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */