// contest
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int nrows = A.size();
        int ncols = A[0].size();
        int res = 0;
        set<pair<int, int>> lessThan;
        for (int col = 0; col < ncols; col++) {

            bool sorted = true;
            set<pair<int, int>> maybeLessThan;
            for (int row = 0; row < nrows - 1; row++) {
                if (lessThan.count({row, row + 1}) == 1) {
                    continue;
                }
                if (A[row][col] < A[row + 1][col]) {
                    maybeLessThan.insert({row, row + 1});
                } else if (A[row][col] > A[row + 1][col]) {
                    sorted = false;
                }
            }
            if (!sorted) {
                res++;
            } else {
                for (auto p: maybeLessThan) {
                    lessThan.insert(p);
                }
            }
        }
        return res;
    }
};
