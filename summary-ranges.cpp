class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        if (A.empty()) {
            return {};
        }
        int from = A[0];
        int to = A[0];
        A.push_back(A.back() + 2);
        vector<string> res;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] - 1 != to) {
                res.push_back(to_string(from) + (from != to ? "->" + to_string(to) : ""));
                from = A[i];
            }
            to = A[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        vector<string> res;
        int i = 0;
        while (i < A.size()) {
            int j = i;
            while (j < A.size() - 1 && A[j + 1] == A[j] + 1) {
                j++;
            }
            res.push_back(to_string(A[i]) + (i != j ? "->" + to_string(A[j]) : ""));
            i = j + 1;
        }
        return res;
    }
};

