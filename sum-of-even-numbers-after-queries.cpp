class Solution {
public:
    bool even(int x) {
        return ((x % 2) + 2) % 2 == 0;
    }
    
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int s = 0;
        for (auto x: A) {
            if (even(x)) {
                s += x;
            }
        }
        for (auto vq: queries) {
            int val = vq[0];
            int i = vq[1];
            if (even(A[i])) {
                if (even(val)) {
                    s += val;
                } else {
                    s -= A[i];
                }
            } else {
                if (!even(val)) {
                    s += A[i] + val;
                } 
            }
            A[i] += val;
            res.push_back(s);
        }
        return res;
    }
};
