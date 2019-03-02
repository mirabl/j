class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n < 2) {
            return true;
        }
        return (n & 1) != ((n >> 1) & 1) && hasAlternatingBits(n >> 1);
    }
};
