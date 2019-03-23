class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        for (char c = 'a'; c <= 'z'; c++) {
            int mC = 1e8;
            for (auto s: A) {
                int cnt = 0;
                for (auto x: s) {
                    if (x == c) {
                        cnt++;
                    }
                }
                mC = min(mC, cnt);
            }
            for (int i = 0; i < mC; i++) {
                res.push_back(string(1,c));
            }
        }
        
        return res;
    }
};
