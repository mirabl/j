class Solution {
public:
    vector<vector<int>> split(vector<int>& A, int atMost) {
        vector<vector<int>> res;
        vector<int> cur;
        A.push_back(atMost + 1);
        for (int x: A) {
            if (x > atMost) {
                if (!cur.empty()) {
                    res.push_back(cur);
                    cur.clear();
                }
            } else {
                cur.push_back(x);
            }
        }
        return res;
    }
    
    int countSubArrays(vector<int>& A, int atLeast) {
        int res = 0;
        int N = A.size();
        int numSkipped = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] >= atLeast) {
                res += (numSkipped + 1) * (N - i);
                numSkipped = 0;
            } else {
                numSkipped++;
            }
        }
        return res;
    }
    
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int atLeast = L;
        int atMost = R;
        int res = 0;

        vector<vector<int>> Bs = split(A, atMost);
        for (auto B: Bs) {
            res += countSubArrays(B, atLeast);
        }
        return res;
    }
};
