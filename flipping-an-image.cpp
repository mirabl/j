// https://leetcode.com/problems/flipping-an-image/description/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> B;
        for (auto row: A) {
            vector<int> row2;
            for (int c = int(row.size()) - 1; c >= 0; c--) {
                row2.push_back(1 - row[c]);
            }
            B.push_back(row2);
        }
        return B;
    }
};
