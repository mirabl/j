// https://leetcode.com/problems/positions-of-large-groups/description/
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int i = 0;
        while (i < int(S.size())) {
            int start = i;
            int end = i;
            while (end + 1 < S.size() && S[end + 1] == S[start]) {
                end++;
            }
            if (end - start >= 2) {
                res.push_back({start, end});
            }
            i = end + 1;
        }
        return res;
    }
};