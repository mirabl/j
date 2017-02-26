class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        int res = 0;
        int n = A.size();
        vector<int> MWEP(n, 1);
        vector<int> MWEN(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] > A[j]) {
                    MWEP[i] = max(MWEP[i], 1 + MWEN[j]);
                } else if (A[i] < A[j]) {
                    MWEN[i] = max(MWEN[i], 1 + MWEP[j]);
                }
            }
            res = max(res, max(MWEP[i], MWEN[i]));
        }
        
        return res;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        int n = A.size();
        int down = 1;
        int up = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                up = down + 1;
            } else if (A[i] < A[i - 1]) {
                down = up + 1;
            }
        }
        return A.empty() ? 0 : max(up, down);
    }
};

