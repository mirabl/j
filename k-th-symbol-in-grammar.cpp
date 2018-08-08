// https://leetcode.com/problems/k-th-symbol-in-grammar/description/
class Solution {
public:
    int rec(int N, int K) {
        if (N == 1) {
            return 0;
        }
        int x = rec(N - 1, K / 2);
        return K % 2 == 0 ? x : 1 - x;
    }
    
    int kthGrammar(int N, int K) {
        return rec(N, K -1);
    }
};
