class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int lo = 1; 
        int hi = x;
        while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
            int y = mid * mid;
            if (y / mid != mid) {
                hi = mid;
            } else if (y > x) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return lo;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int lo = 1; 
        int hi = x;
        while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
            if (mid > x / mid) { // Avoid overflow.
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return lo;
    }
};
