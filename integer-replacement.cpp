class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        } else {
            if (n == 2147483647) {
                return 1 + min(integerReplacement(n - 1), 1 + integerReplacement(1 << 30));
            }
            return 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
        }
    }
};

// better overflow
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        } else {
            return 2 + min(integerReplacement(1 + (n - 1) / 2), integerReplacement((n - 1) / 2));
        }
    }
};