class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> M;
        for (string s: strs) {
            string t(s);
            sort(t.begin(), t.end());
            M[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto x: M) {
            res.push_back(x.second);
        }
        return res;
    }
};