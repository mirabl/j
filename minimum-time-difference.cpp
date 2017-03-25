class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> A;
        for (string s: timePoints) {
            A.push_back(60 * (10 * int(s[0] - '0') + int(s[1] - '0')) + 10 * int(s[3] - '0') + int(s[4] - '0'));
        }
        sort(A.begin(), A.end());
        A.push_back(24 * 60 + A[0]);
        int m = A[1] - A[0];
        for (int i = 2; i < A.size(); i++) {
            m = min(m, A[i] - A[i - 1]);
        }
        return m;
    }
};

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> A;
        for (string s: timePoints) {
            A.push_back(60 * stoi(s.substr(0, 2)) + stoi(s.substr(3)));
        }
        sort(A.begin(), A.end());
        A.push_back(24 * 60 + A[0]);
        int m = A[1] - A[0];
        for (int i = 2; i < A.size(); i++) {
            m = min(m, A[i] - A[i - 1]);
        }
        return m;
    }
};

