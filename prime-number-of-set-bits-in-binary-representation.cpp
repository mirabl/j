class Solution {
public:
    int numBits(int x) {
        int n = 0;
        for (int i = 0; i < 31; i++) {
            if ((x >> i) & 1 == 1) {
                n++;
            }
        }
        return n;
    }
    
    bool isPrime(int x) {
        set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        return primes.count(x) == 1;
    }
    
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int x = L; x <= R; x++) {
            if (isPrime(numBits(x))) {
                res++;
            }
        }
        return res;
    }
};