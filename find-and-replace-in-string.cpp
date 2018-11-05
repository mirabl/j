	// https://leetcode.com/problems/find-and-replace-in-string/description/
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res;
        int m = int(indexes.size());
        
        map<int, vector<int>> M;
        for (int i = 0; i < int(indexes.size()); i++) {
            M[indexes[i]].push_back(i);
        }
        
        int i = 0;
        while (i < S.size()) {
            bool matched = false;
            for (auto j: M[i]) {
                int pat_len = sources[j].size();
                if (S.substr(i, pat_len) == sources[j]) {
                    res += targets[j];
                    i += pat_len;
                    matched = true;
                    break;
                }
            }
            if (!matched) {
                res += S[i];
                i++;
            }
        }
        return res;
    }
};
