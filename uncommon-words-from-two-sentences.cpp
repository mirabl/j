class Solution {
public:
    
    vector<string> words(string s) {
        vector<string> W;
        string cur;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            
            int j = i + 1;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            
            W.push_back(s.substr(i, j - i));
            i = j;
        }
        
        return W;
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> wA = words(A);
        vector<string> wB = words(B);
        map<string, int> c;
        for (auto s: wA) {
            c[s]++;
        }
        for (auto s: wB) {
            c[s]++;
        }
        
        vector<string> ans;
        
        for (auto kvp: c) {
            if (kvp.second == 1) {
                ans.push_back(kvp.first);
            }
        }
        return ans;
    }
};
