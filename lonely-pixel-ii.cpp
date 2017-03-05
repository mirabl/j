class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int nrows = picture.size();
        int ncols = picture.empty() ? 0 : picture[0].size();
        vector<int> arows(nrows);
        vector<int> acols(ncols);
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (picture[row][col] == 'B') {
                    arows[row]++;
                    acols[col]++;
                }
            }
        }
        int res = 0;
        for (int row = 0; row < nrows; row++) {
            for (int col = 0; col < ncols; col++) {
                if (picture[row][col] == 'B' && arows[row] == N && acols[col] == N) {
                    bool same_rows = true;
                    for (int row2 = 0; row2 < nrows; row2++) {
                        if (picture[row2][col] == 'B') {
                            same_rows &= (picture[row] == picture[row2]);
                        }
                    }
                    if (same_rows) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};