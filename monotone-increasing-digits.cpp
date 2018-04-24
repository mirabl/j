class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int y = 0;
        for (int d = 1e9; d > 0; d /= 10) {
            if (d > N) {
                continue;
            }
            int a = (N / d) % 10;
            int b = d > 1 ? (N / (d / 10)) % 10 : 10;
            if (a <= b) {
                y += a * d;
            } else {
                y += (a * d) - 1;
                return monotoneIncreasingDigits(y);
            }
        }
        return y;
    }
};

