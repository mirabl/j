/*
https://leetcode.com/problems/4sum-ii/
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> X;
        unordered_map<int, int> Y;
        for (int a: A) {
            for (int b: B) {
                X[a + b]++;
            }
        }
        int n = 0;
        for (int c: C) {
            for (int d: D) {
                if (X.count(- c - d) != 0) {
                    n += X[- c - d];
                }
            }
        }
        return n;
    }
};