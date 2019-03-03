class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        } else if (N == 1) {
            return 1;
        }
        
        int x = 1;
        int y = 0;
        
        for (int i = 2; i <= N; i++) {
            int t = x + y;
            y = x;
            x = t;
        } 
        
        return x;
    }
};
