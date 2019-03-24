class Solution {
public:
    // 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1

    // 8 * 7 / 6 + 5 - 4 * 3 / 2 + 1
    // 9+5 - 6+1
    // 
    
    int f(int N, bool first) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2 * 1;
        } else if (N == 3) {
            return (3 * 2) / 1;
        } else if (N == 4) {
            return ((4 * 3) / 2) + ((first ? 1 : -1) * 1); 
        } else {
            return ((N * (N - 1) / (N - 2)) + ((first ? 1 : -1) * (N - 3)));
        }
    }
    
    int clumsy(int N) {
        int res = f(N, true);
         //cout << "res=" << res << endl;
        N -= 4;
        while (N > 0) {
            res -= f(N, false);
         //   cout << "res=" << res << endl;

            N -= 4;
        }
        return res;
    }
};
