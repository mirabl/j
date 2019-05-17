class Solution {
public:
    bool r(int N, map<int, bool>& memo) {
        if (memo.count(N) == 1) {
            return memo[N];
        }
        
        memo[N] = false;
        for (int x = 1; x < N; x++) {
            if (N % x == 0) {
                if (!r(N - x, memo)) {
                    memo[N] = true;
                }
            }
        }
        cout << "memo " << N << ": " << memo[N] << endl;
        return memo[N];
    }
    
    bool divisorGame(int N) {
        map<int, bool> memo;
        return r(N, memo);
    }
};
