class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int nrows = picture.size();
        int ncols = picture.empty() ? 0 : picture[0].size();
        vector<int> rows(nrows);
        vector<int> cols(ncols);
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (picture[row][col] == 'B') {
                    rows[row]++;
                    cols[col]++;
                }
            }
        }
        int res = 0;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (picture[row][col] == 'B' && rows[row] == 1 && cols[col] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};