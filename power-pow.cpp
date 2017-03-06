class Solution {
public:
    int superPow(int a, vector<int>& b) {
        reverse(b.begin(), b.end());
        int s = 1;
        int M = 1337;
        a = a % M;
        for (int bi: b) {
            for (int i = 0; i < bi; i++) {
                s = (s * a) % M;
            }
            int r = 1;
            for (int i = 0; i < 10; i++) {
                r = (a * r) % M;
            }
            a = r;
        }
        return s;
    }
};

