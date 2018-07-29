// https://leetcode.com/problems/consecutive-numbers-sum/description/
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        
        int n = 1;
        while (true) {
            int p = N - (n * (n - 1)) / 2;
            if (p <= 0) {
                break;
            }
            if (p % n == 0) {
                res++;
            }
            n++;
        }
        return res;
    }
};