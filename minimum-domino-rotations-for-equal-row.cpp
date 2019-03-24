class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int infty = 1e8;
        int best = infty;
        int n = A.size();
        for (int c = 1; c <= 6; c++) {
            int topCnt = 0;
            int botCnt = 0;
            for (int i = 0; i < n; i++) {
                if (A[i] == c && B[i] != c) {
                    botCnt++;
                } else if (A[i] != c && B[i] == c) {
                    topCnt++;
                } else if (A[i] != c && B[i] != c) {
                    botCnt = infty;
                    topCnt = infty;
                    break;
                } 
            }
            best = min(best, topCnt);
            best = min(best, botCnt);
        }
        return best != infty ? best : -1;
    }
};
