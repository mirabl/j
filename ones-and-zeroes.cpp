/*
https://leetcode.com/problems/ones-and-zeroes/
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> A(m + 1, vector<int>(n + 1));
        vector<vector<int>> B(m + 1, vector<int>(n + 1)); // B is initialized with zeroes.
        for (string s: strs) {
            int n0 = count(s.begin(), s.end(), '0');
            int n1 = int(s.size()) - n0;
            for (int ni = 0; ni < n + 1; ni++) {
                for (int mi = 0; mi < m + 1; mi++) {
                    if (mi >= n0 && ni >= n1) {
                        A[mi][ni] = max(B[mi][ni], 1 + B[mi - n0][ni - n1]); // 1 for first string.
                    } else {
                        A[mi][ni] = B[mi][ni]; // 0 for first string.
                    }
                }
            }
            swap(A, B);
        }
        return B[m][n];
    }
};