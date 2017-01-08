/*
https://leetcode.com/problems/valid-perfect-square/
*/
// Potential overflows.
class Solution {
public:
    double sqr(int n) {
        double x = double(n);
        if (n <= 1) {
            return n;
        }
        double lo = 0;
        double hi = n;
        double mid;
        double e = 0.00001;
        while (hi - lo > e) {
            mid = (hi + lo) / 2;
            if (mid * mid > x) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }

    bool isPerfectSquare(int num) {
        double s = sqr(num);
        int i = int(s);
        return i * i == num;
    }
};