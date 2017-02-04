class Solution {
public:
    int magicalString(int n) {
        vector<int> A{1, 2, 2};
        for (int i = 2; A.size() < n; i++) {
            A.insert(A.end(), A[i], 3 - A.back());
        }
        return count(A.begin(), A.begin() + n, 1);
    }
};